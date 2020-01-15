#include "../includes/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/10 18:29:25 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max_of_partition(t_stack *start, t_stack *end)
{
	t_stack *tmp;
	int max;

	tmp = start;
	max = start->value;
	while (tmp != end)
	{
		tmp = tmp->next;
		if (tmp != NULL && tmp->value > max)
			max = tmp->value;
	}
	return (max);
}

int get_min_of_partition(t_stack *start, t_stack *end)
{
	t_stack *tmp;
	int min;

	tmp = start;
	min = start->value;
	while (tmp != end)
	{
		tmp = tmp->next;
		if (tmp != NULL && tmp->value < min)
			min = tmp->value;
	}
	return (min);
}

void free_partition(t_stacks *stacks, int partition_cap)
{
	if (stacks->partitions[partition_cap]->end)
		stacks->partitions[partition_cap]->end = NULL;
	if (stacks->partitions[partition_cap]->start)
		stacks->partitions[partition_cap]->start = NULL;
}

void sort_tree_elems_b(t_stacks *stacks, int count)
{
	int skip;
	int max;
	int count_elements_in_part;

	skip = 0;
	count_elements_in_part = get_elems_count_b(stacks) == count ? get_elems_count_b(stacks) : count;
	if (!stacks->stack_b)
		return;
	if (count_elements_in_part < 3)
	{
		while (!((stacks->stack_b)->next->value > (stacks->stack_b)->next->next->value && (stacks->stack_b)->value > (stacks->stack_b)->next->next->value))
		{
			if ((stacks->stack_b)->next->value < (stacks->stack_b)->next->next->value && (stacks->stack_b)->next->value < (stacks->stack_b)->value)
			{
				ft_apply_rr(&stacks->stack_b);
				//print_stacks(stacks->stack_a, stacks->stack_b);
				ft_putstr("rrb\n");
			}
			else {
				ft_apply_r(&stacks->stack_b);
				//print_stacks(stacks->stack_a, stacks->stack_b);
				ft_putstr("rb\n");
			}
		}
		ft_apply_s(&stacks->stack_b);
		//print_stacks(stacks->stack_a, stacks->stack_b);
		ft_putstr("sb\n");
	}
	else /* TODO Ошибка в сортинге, он не учитывает, что в partition могут быть элементы больше или меньше текущих
		 	TODO трех, соответсвенно кидает в А не то что нужно. *СДЕЛАТЬ ПРОВЕРКУ НА ТО, ЧТО МОЖНО КИДАТЬ В А* */
	{
//		update_partition(stacks);
		max = get_max_of_partition(stacks->partitions[stacks->partition_cap]->start,
								   stacks->partitions[stacks->partition_cap]->end);
		while ((stacks->stack_b)->value < max) {
			ft_apply_r(&stacks->stack_b);
			ft_putstr("rb\n");
			skip++;
		}
		ft_apply_p(&stacks->stack_b, &stacks->stack_a);
		while (skip) {
			ft_apply_rr(&stacks->stack_b);
			ft_putstr("rrb\n");
			skip--;
		}
		if ((stacks->stack_b)->value < (stacks->stack_b)->next->value)
		{
			ft_apply_s(&stacks->stack_b);
			ft_putstr("sb\n");

		}
	}
	stacks->partitions[stacks->partition_cap]->start = stacks->stack_b;
	if (stacks->partition_cap > 0)
		stacks->partitions[stacks->partition_cap]->end = stacks->partitions[stacks->partition_cap - 1]->start->prev;

//	stacks->stack_a_top = stacks->stack_a;
	//print_stacks(stacks->stack_a, stacks->stack_b);
//	stacks->stack_b_top[++stacks->partition_cap] = stacks->stack_b;
//	update_partition(stacks);
//	stacks->partition_cap--;
}

void sort_b(t_stacks *stacks,  int capacity)
{
	int count;
	t_stack *tmp;

	count = 0;
	tmp = stacks->stack_b;
	if (tmp == NULL)
		return;
	if (capacity == 1)
		return;
	else if (capacity == 2) {
		if (stacks->stack_b->next->value > stacks->stack_b->value) {
			ft_apply_s(&stacks->stack_b);
			ft_putstr("sb");
			//print_stacks(stacks->stack_a, stacks->stack_b);
			stacks->stack_a_top = stacks->stack_b;
			update_partition(stacks);
//			stacks->partition_cap--;
		}
	}
	else
		sort_tree_elems_b(stacks, capacity);
}

void update_partition(t_stacks *stacks)
{
	t_stack *tmp;

	tmp = stacks->stack_b;
	if (tmp == NULL)
		return;
	if (stacks->partition_cap > 0 && stacks->stack_b != stacks->partitions[stacks->partition_cap]->start)
	{
		stacks->partitions[stacks->partition_cap]->start = tmp;
		while (tmp->next != stacks->partitions[stacks->partition_cap - 1]->start && tmp->next)
		{
//			if (tmp == stacks->partitions[stacks->partition_cap - 1]->start)
//				break;
			tmp = tmp->next;
		}
		stacks->partitions[stacks->partition_cap]->end = tmp;
	}
	else if (stacks->partition_cap == 0 && stacks->stack_b != stacks->partitions[stacks->partition_cap]->start)
	{
		stacks->partitions[stacks->partition_cap]->start = tmp;
		while (tmp->next != stacks->partitions[stacks->partition_cap]->end && tmp->next)
			tmp = tmp->next;
		stacks->partitions[stacks->partition_cap]->end = tmp;
	}
}

void push_more_than_median_to_a(t_stacks *stacks, int median)
{
	int skip;

	skip = 0;
//	stacks->partition_cap++;
	while (stacks->stack_b)
	{
		if (stacks->stack_b->value >= median)
		{
			ft_apply_p(&stacks->stack_b, &stacks->stack_a);
			//print_stacks(stacks->stack_a, stacks->stack_b);
			ft_putstr("pb\n");
			if (stacks->stack_b == stacks->partitions[stacks->partition_cap]->end && stacks->stack_b->value >= median)
			{
				ft_apply_p(&stacks->stack_b, &stacks->stack_a);
				ft_putstr("pb\n");
				//print_stacks(stacks->stack_a, stacks->stack_b);
				break;
			}
		}
		else {
			ft_apply_r(&stacks->stack_b);
			//print_stacks(stacks->stack_a, stacks->stack_b);
			ft_putstr("rb\n");
			skip++;
			if (stacks->stack_b == stacks->partitions[stacks->partition_cap]->end)
				break;
		}
	}
	while (skip > 0)
	{
		ft_apply_rr(&stacks->stack_b);
		print_stacks(stacks->stack_a, stacks->stack_b);
		ft_putstr("rrb\n");
		skip--;
	}
	update_partition(stacks);
}

int get_elems_count_b(t_stacks *stacks)
{
	t_stack *tmp;
	int count;

	count = 1;

	if (stacks->stack_b)
	{
		tmp = stacks->stack_b;
//		count++;
//		if (stacks->partition_cap > 0 && stacks->partitions[stacks->partition_cap]->start == NULL)
//			stacks->partition_cap--;
		while (tmp != stacks->partitions[stacks->partition_cap]->end && count < 12)
		{
			tmp = tmp->next;
			count++;
		}
		return (count);
	}
	return (-1);
}


static void push_b(t_stacks *stacks, t_stack **stack_b, int capacity)
{
	int i;

	i = 0;
	capacity = (capacity == -1) ? 3 : capacity;
	while (i < capacity)
	{
		ft_apply_p(stack_b, &stacks->stack_a);
		ft_putstr("pa\n");
		if (stacks->partition_cap > 0 && stacks->stack_b == stacks->partitions[stacks->partition_cap - 1]->start)
			stacks->partition_cap--;
		i++;
	}
	print_stacks(stacks->stack_a, stacks->stack_b);
	update_partition(stacks);
//	stacks->partition_cap--;
}

int b_to_a(t_stacks *stacks)
{
	int median;
	int elems_count;

	median = MAX_INTEGER;
//	update_partition(stacks);
	elems_count = get_elems_count_b(stacks);
	stacks->partition_cap_final_flag = 1;
	if (elems_count <= 6 && elems_count > 3)
	{
		median = special_median_b(stacks, elems_count);
		printf("SPECIAL median B = %d\n", median);
	}
	else if (elems_count > 6)
	{
		median = special_median_b(stacks, elems_count);
		printf("TRUE median B = %d\n", median); // 44 45 47 64 68 81 96
	}
	if (median != MAX_INTEGER)
	{
		push_more_than_median_to_a(stacks, median);
		print_stacks(stacks->stack_a, stacks->stack_b);
		printf("split round median B = %d\n", median);
	}
	else
	{
		sort_b(stacks, elems_count);
		print_stacks(stacks->stack_a, stacks->stack_b);
		if (elems_count == 3)
			elems_count--;
	}
	if (median == MAX_INTEGER)
	{
		push_b(stacks, &stacks->stack_b, elems_count);
//		free_partition(stacks, stacks->partition_cap);
//		stacks->partition_cap--;
		print_stacks(stacks->stack_a, stacks->stack_b);
	}
	return (median == MAX_INTEGER ? 0 : 1);
}