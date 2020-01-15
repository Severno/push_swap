/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/15 16:15:48 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				is_sorted(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->next)
		{
			if (stack_a->value > stack_a->next->value)
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

void sort_three_elems(t_stack **a, t_stacks *stacks)
{
	int skip;
	int min;
	int count_elements_in_part;

	skip = 0;
	count_elements_in_part = get_elems_count_a(*a, stacks);
	if (count_elements_in_part < 3)
	{
		while ((*a)->next->next->value < (*a)->next->value && (*a)->next->value < (*a)->value)
		{
			if ((*a)->value <(*a)->next->value != 0 > (*a)->next->next->value)
			{
				ft_apply_r(a);
				ft_putstr("ra\n");
			}
			else {
				ft_apply_s(a);
				//print_stacks(*a, stacks->stack_b);
				ft_putstr("sa\n");
				ft_apply_rr(a);
				//print_stacks(*a, stacks->stack_b);
				ft_putstr("ra\n");
			}
		}
	}
	else
	{
		min = get_min_of_partition(stacks->stack_a,
								   stacks->stack_a_top);
		while ((*a)->value > min && (*a) != stacks->stack_a_top)
		{
			ft_apply_r(a);
			ft_putstr("ra\n");
			skip++;
		}
		ft_apply_p(a, &stacks->stack_b);
		ft_putstr("pb\n");
		while (skip)
		{
			ft_apply_rr(a);
			ft_putstr("rra\n");
			skip--;
		}
		if ((*a)->value > (*a)->next->value)
		{
			ft_apply_s(a);
			ft_putstr("sa\n");
		}
	}
	ft_apply_p(&stacks->stack_b, a);
	ft_putstr("pa\n");
//	stacks->partition_cap--;
	stacks->stack_a_top = *a;
}

void sort_a(t_stack **a, t_stacks *stacks,  int capacity)
{
	if (capacity == 1)
		return ;
	if (capacity == 2) {
		if ((*a)->next->value < (*a)->value) {
			ft_apply_s(a);
			ft_putstr("sa\n");
			stacks->stack_a_top = *a;
		}
		return;
	}
	sort_three_elems(a, stacks);
}

static int get_less_then_num_count(t_stack *stack, int median)
{
	int count;
	t_stack *tmp;

	count = 0;
	tmp = stack;
	if (!stack)
		return (0);
	while (tmp)
	{
		if (tmp->value <= median)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

//static void true_split_a_to_b(t_stacks *stacks, int median)
//{
//	int pushed;
//	int count_less_median;
//
//	pushed = 0;
//	count_less_median = get_less_then_num_count(stacks->stack_a, median);
//	if (stacks->partition_cap_final_flag == 0)
//		stacks->partition_cap++;
//	while (pushed <= count_less_median - 1)
//	{
//		if (stacks->stack_a->value <= median)
//		{
//			ft_apply_p(&stacks->stack_a, &stacks->stack_b);
//			ft_putstr("pb\n");
//			pushed++;
////			print_stacks(stacks->stack_a, stacks->stack_b);
//		}
//		else
//			{
//			ft_apply_r(&stacks->stack_a);
//			ft_putstr("ra\n");
////			print_stacks(stacks->stack_a, stacks->stack_b);
//		}
//	}
//	stacks->partitions[stacks->partition_cap]->start = stacks->stack_b;
//	if (stacks->partition_cap > 0)
//		stacks->partitions[stacks->partition_cap]->end = stacks->partitions[stacks->partition_cap - 1]->start->prev;
//	else
//		stacks->partitions[stacks->partition_cap]->end = get_last_stack_elem(stacks->stack_b);
//}

void push_less_than_median_to_b(t_stacks *stacks, int median, int elems_count)
{
	int flag;
	int skip;
	int less_count;

	skip = 0;
	flag = 0;
	less_count = get_less_then_num_count(stacks->stack_a, median);
//	if (stacks->partition_cap_final_flag == 0)
		stacks->partition_cap++;
	while (stacks->stack_a != stacks->stack_a_top && less_count > 0)
	{
		if (stacks->stack_a->value <= median)
		{
			if (stacks->partition_cap_final_flag == 1)
			{
				if (flag == 0)
				{
					stacks->partitions[stacks->partition_cap]->start = stacks->stack_a;
					stacks->partitions[stacks->partition_cap]->end = stacks->stack_a;
					flag = 1;
				}
				else
					stacks->partitions[stacks->partition_cap]->start = stacks->stack_a;
			}
			ft_apply_p(&stacks->stack_a, &stacks->stack_b);
			ft_putstr("pb\n");
			less_count--;
			--elems_count;
			//print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else {
			if (less_count <= 0)
				break;
			ft_apply_r(&stacks->stack_a);
//			print_stacks(stacks->stack_a, stacks->stack_b);
			ft_putstr("ra\n");
			skip++;
		}
	}
	//print_stacks(stacks->stack_a, stacks->stack_b);
	if (stacks->stack_a_top != NULL && stacks->partition_cap_final_flag == 1)
	{
		while (skip > 0)
		{
			ft_apply_rr(&stacks->stack_a);
//			print_stacks(stacks->stack_a, stacks->stack_b);
			ft_putstr("rra\n");
			skip--;
		}
	}
//	print_stacks(stacks->stack_a, stacks->stack_b);
	if (stacks->partition_cap_final_flag == 0 && stacks->stack_b)
	{
		stacks->partitions[stacks->partition_cap]->start = stacks->stack_b;
		if (stacks->partition_cap > 0)
			stacks->partitions[stacks->partition_cap]->end = stacks->partitions[stacks->partition_cap - 1]->start->prev;
		else
			stacks->partitions[stacks->partition_cap]->end = get_last_stack_elem(stacks->stack_b);
	}

}
int get_elems_count_a(t_stack *stack, t_stacks *stacks)
{
	t_stack *tmp;
	int count;

	count = 0;
	if (stack)
	{
		tmp = stack;
//		count++;
		while (tmp != stacks->stack_a_top && tmp)
		{
			tmp = tmp->next;
			count++;
		}
		return (count);
	}
	return (-1);
}

int a_to_b(t_stacks *stacks)
{
	int median;
	int elems_count;

	median = MAX_INTEGER;
	elems_count = get_elems_count_a(stacks->stack_a, stacks);
	if (elems_count <= 11 && elems_count > 3)
	{
		median = special_median_a(stacks);
//		printf("Special median A = %d\n", median); // 47 54 68 81 96 98
	}
	else if (elems_count > 11)
	{
		median = true_median(stacks, stacks->stack_a);
//		printf("TRUE median A = %d\n", median);
//		print_stacks(stacks->stack_a, stacks->stack_b);
	}
	if (median != MAX_INTEGER)
	{
		push_less_than_median_to_b(stacks, median, elems_count);
//		//print_stacks(a, b, cmnd);
//		print_stacks(stacks->stack_a, stacks->stack_b);
//		printf("split_round_median median A = %d\n", median);
	}
	if (median == MAX_INTEGER)
	{
		sort_a(&stacks->stack_a, stacks, elems_count);
//		print_stacks(stacks->stack_a, stacks->stack_b);
	}
	if (median == MAX_INTEGER)
		stacks->stack_a_top = stacks->stack_a;
//	print_stacks(stacks->stack_a, stacks->stack_b);
	return (median == MAX_INTEGER ? 0 : 1);
}