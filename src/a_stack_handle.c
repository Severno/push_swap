/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/11 19:48:57 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_tree_elems(t_stack **a, t_stacks *stacks)
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
	sort_tree_elems(a, stacks);
}

void push_less_than_median_to_b(t_stack *stack_a, t_stacks *stacks, int median)
{
	int top_value;

	top_value = stack_a->value;
	stacks->partition_cap++;
	while (stack_a != stacks->stack_a_top)
	{
		if (stack_a->value <= median)
		{
			if (stacks->partitions[stacks->partition_cap]->end == NULL
			&& stacks->partitions[stacks->partition_cap]->start == NULL)
			{
				stacks->partitions[stacks->partition_cap]->start = stack_a;
				stacks->partitions[stacks->partition_cap]->end = stack_a;
			}
			else
				stacks->partitions[stacks->partition_cap]->start = stack_a;
			ft_apply_p(&stack_a, &stacks->stack_b);
			ft_putstr("pb\n");
		}
		else {
			ft_apply_r(&stack_a);
			print_stacks(stack_a, stacks->stack_b);
			ft_putstr("ra\n");
			if (stack_a->value == top_value)
				break;
		}
	}
}
int get_elems_count_a(t_stack *stack, t_stacks *stacks)
{
	t_stack *tmp;
	int count;

	tmp = stack;
	count = 0;
	if (tmp == NULL)
		return (-1);
	while (tmp != stacks->stack_a_top && count < 12)
	{
		tmp = tmp->next;
		count++;
	}
	if (stacks->stack_a_top && count == 3)
		return (-1);
	return (count);
}

int a_to_b(t_stacks *stacks)
{
	int median;
	int elems_count;

	median = MAX_INTEGER;
	elems_count = get_elems_count_a(stacks->stack_a, stacks);
	if (elems_count <= 3)
	{
		sort_a(&stacks->stack_a, stacks, elems_count);
		return (0);
	}
	else if (elems_count >= 4)
	{
		median = true_median(stacks, stacks->stack_a); // TODO добавить special median, для partition
		push_less_than_median_to_b(stacks->stack_a, stacks, median);
		printf("True median A = %d\n", median);
	}
	if (median == MAX_INTEGER)
		stacks->stack_a_top = stacks->stack_a;
	print_stacks(stacks->stack_a, stacks->stack_b);
	return (median == MAX_INTEGER ? 0 : 1);
}