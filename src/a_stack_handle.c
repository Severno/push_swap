/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/13 20:09:34 by sapril           ###   ########.fr       */
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
				print_stacks(*a, stacks->stack_b);
				ft_putstr("sa\n");
				ft_apply_rr(a);
				print_stacks(*a, stacks->stack_b);
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
			ft_putstr("sa");
			stacks->stack_a_top = *a;
		}
		return;
	}
	sort_three_elems(a, stacks);
}

void push_less_than_median_to_b(t_stacks *stacks, int median, int elems_count)
{
	int top_value;
	int skip;

	skip = 0;
	top_value = stacks->stack_a->value;
	stacks->partition_cap++;
	while (stacks->stack_a != stacks->stack_a_top)
	{
		if (stacks->stack_a->value <= median)
		{
			if (stacks->partitions[stacks->partition_cap]->end == NULL
			&& stacks->partitions[stacks->partition_cap]->start == NULL)
			{
				stacks->partitions[stacks->partition_cap]->start = stacks->stack_a;
				stacks->partitions[stacks->partition_cap]->end = stacks->stack_a;
			}
			else
				stacks->partitions[stacks->partition_cap]->start = stacks->stack_a;
			ft_apply_p(&stacks->stack_a, &stacks->stack_b);
			ft_putstr("pb\n");
			--elems_count;
		}
		else {
			if (--elems_count <= 0)
				break;
			ft_apply_r(&stacks->stack_a);
			print_stacks(stacks->stack_a, stacks->stack_b);
			ft_putstr("ra\n");
			skip++;
		}
	}
	print_stacks(stacks->stack_a, stacks->stack_b);
	if (stacks->stack_a_top != NULL)
	{
		while (skip > 0)
		{
			ft_apply_rr(&stacks->stack_a);
			print_stacks(stacks->stack_a, stacks->stack_b);
			ft_putstr("rra\n");
			skip--;
		}
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
		while (tmp != stacks->stack_a_top && count < 12)
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
		printf("Special median A = %d\n", median);
	}
	else if (elems_count > 11)
	{
		median = true_median(stacks, stacks->stack_a);
		printf("TRUE median A = %d\n", median);
	}
	if (median != MAX_INTEGER)
	{
		push_less_than_median_to_b(stacks, median, elems_count);
//		print_stacks(a, b, cmnd);
		print_stacks(stacks->stack_a, stacks->stack_b);
		printf("split_round_median median A = %d\n", median);
	}
	else
	{
		sort_a(&stacks->stack_a, stacks, elems_count);
		print_stacks(stacks->stack_a, stacks->stack_b);
	}
	if (median == MAX_INTEGER)
		stacks->stack_a_top = stacks->stack_a;
	print_stacks(stacks->stack_a, stacks->stack_b);
	return (median == MAX_INTEGER ? 0 : 1);
}