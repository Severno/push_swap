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

void sort_tree_elems_b(t_stack **b, t_stacks *stacks)
{
	int skip;
	int max;
	int count_elements_in_part;

	skip = 0;
	count_elements_in_part = get_elems_count_b(*b, stacks);
	if (count_elements_in_part < 3)
	{
		while (!((*b)->next->value > (*b)->next->next->value && (*b)->value > (*b)->next->next->value))
		{
			if ((*b)->next->value < (*b)->next->next->value && (*b)->next->value < (*b)->value)
			{
				ft_apply_rr(b);
				print_stacks(stacks->stack_a, *b);
				ft_putstr("rrb\n");
			}
			else {
				ft_apply_r(b);
				print_stacks(stacks->stack_a, *b);
				ft_putstr("rb\n");
			}
		}
		ft_apply_s(b);
		print_stacks(stacks->stack_a, *b);
		ft_putstr("sb\n");
	}
	else
	{
		max = get_max_of_partition(stacks->partitions[stacks->partition_cap]->start,
				stacks->partitions[stacks->partition_cap]->end);
		while ((*b)->value < max)
		{
			ft_apply_r(b);
			skip++;
		}
		ft_apply_p(b, &stacks->stack_a);
		while (skip)
		{
			ft_apply_rr(b);
			skip--;
		}
		if ((*b)->value > (*b)->next->value)
		{
			ft_apply_p(b, &stacks->stack_a);
			ft_apply_p(b, &stacks->stack_a);
		} else {
			ft_apply_s(b);
			ft_apply_p(b, &stacks->stack_a);
			ft_apply_p(b, &stacks->stack_a);
			stacks->stack_a_top = stacks->stack_a;
		}
	}
	stacks->partition_cap--;
//	stacks->stack_b_top[++stacks->partition_cap] = *b;
}

void sort_b(t_stack **b, t_stacks *stacks,  int capacity)
{
	if (capacity == 0)
		return ;
	if (capacity == 1) {
		if ((*b)->next->value < (*b)->value) {
			ft_apply_s(b);
			ft_putstr("sb");
			print_stacks(stacks->stack_a, *b);
			stacks->stack_a_top = *b;
		}
		return;
	}
	sort_tree_elems_b(b, stacks);
}

//void push_sorted_b_to_a(t_stack **stack_b, t_stacks *stacks)
//{
//	int i;
//
//	i = 0;
//	while (i < 3)
//	{
//		ft_apply_p(stack_b, &stacks->stack_a);
//		print_stacks(stacks->stack_a, *stack_b);
//		ft_putstr("pa\n");
//		i++;
//	}
//}
//void push_less_than_median_to_a(t_stack *stack_b, t_stacks *stacks, int median)
//{
//	int top_value;
//
//	top_value = stack_b->value;
//	while (stack_b != stacks->stack_b_top)
//	{
//		if (stack_b->value <= median)
//		{
//			ft_apply_p(&stack_b, &stacks->stack_a);
//			ft_putstr("pb\n");
//		}
//		else {
//			ft_apply_r(&stack_b);
//			print_stacks(stacks->stack_a, stack_b);
//			ft_putstr("ra\n");
//			if (stack_b->value == top_value)
//				break;
//		}
//	}
//}

void push_more_than_median_to_a(t_stack *stack_b, t_stacks *stacks, int median)
{
	int top_value;

	top_value = stack_b->value;
	stacks->partition_cap++;
	while (stack_b != stacks->stack_a_top)
	{
		if (stack_b->value >= median)
		{
			ft_apply_p(&stack_b, &stacks->stack_a);
			print_stacks(stacks->stack_a, stack_b);
			ft_putstr("pb\n");
		}
		else {
			ft_apply_r(&stack_b);
			print_stacks(stacks->stack_a, stack_b);
			ft_putstr("rb\n");
			if (stack_b->value == top_value)
				break;
		}
	}
}

int get_elems_count_b(t_stack *stack, t_stacks *stacks)
{
	t_stack *tmp;
	int count;

	tmp = stack;
	count = 1;
	if (tmp == NULL)
		return (-1);
	while (tmp != stacks->partitions[stacks->partition_cap]->end && count < 12)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}


int b_to_a(t_stacks *stacks)
{
	int median;
	int elems_count;

	median = MAX_INTEGER;
	elems_count = get_elems_count_b(stacks->stack_b, stacks);
	if (elems_count <= 3)
	{
		sort_b(&stacks->stack_b, stacks, elems_count);
		print_stacks(stacks->stack_a, stacks->stack_b);
//		push_sorted_b_to_a(&stacks->stack_b, stacks);
		print_stacks(stacks->stack_a, stacks->stack_b);
		return (0);
	}
	else if (elems_count >= 4)
	{
		median = true_median(stacks, stacks->stack_b);
		push_more_than_median_to_a(stacks->stack_b, stacks, median);
		printf("True median A = %d\n", median);
	}
	return (median == MAX_INTEGER ? 0 : 1);
}