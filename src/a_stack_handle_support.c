/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle_support.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artembykov <artembykov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:02:43 by artembykov        #+#    #+#             */
/*   Updated: 2020/01/22 13:16:24 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		push_and_rotate(t_stacks *stacks,
		int *less_count, int *flag, int median)
{
	int skip;

	skip = 0;
	if (stacks->stack_a->value <= median)
	{
		ft_apply_p(&stacks->stack_a, &stacks->stack_b, stacks);
		if (*flag == 0)
			stacks->partitions[stacks->partition_cap]->end = stacks->stack_b;
		*flag = 1;
		(*less_count)--;
	}
	else
	{
		ft_apply_r(&stacks->stack_a, stacks);
		skip++;
	}
	return (skip);
}

static void		apply_three_sorting_commands(t_stacks *stacks,
		t_stack **a, int skip)
{
	ft_apply_p(a, &stacks->stack_b, stacks);
	stack_step_back(&stacks->stack_a, stacks, skip);
	if ((*a)->value > (*a)->next->value)
		ft_apply_s(a, stacks);
	ft_apply_p(&stacks->stack_b, a, stacks);
}

void			sort_three_elems_a(t_stack **a, t_stacks *stacks)
{
	int skip;
	int min;

	skip = 0;
	min = get_min_of_partition(stacks->stack_a,
			stacks->stack_a_top);
	if (get_stack_size(*a) == 3 && get_stack_size(stacks->stack_b) < 4)
	{
		fast_handle_only_three_elems(a, stacks);
		return ;
	}
	while ((*a)->value > min && (*a) != stacks->stack_a_top)
	{
		ft_apply_r(a, stacks);
		skip++;
	}
	if (get_stack_size(stacks->stack_a) < 7)
		if (is_sorted(stacks->stack_a))
			return ;
	apply_three_sorting_commands(stacks, a, skip);
	update_current_partition(stacks);
	stacks->stack_a_top = *a;
}

void			push_less_than_median_to_b(t_stacks *stacks, int median)
{
	int flag;
	int skip;
	int less_count;

	skip = 0;
	flag = 0;
	less_count = get_less_then_num_count(stacks->stack_a, median);
	stacks->partition_cap++;
	while (stacks->stack_a != stacks->stack_a_top && less_count > 0)
		skip += push_and_rotate(stacks, &less_count, &flag, median);
	stacks->partitions[stacks->partition_cap]->start = stacks->stack_b;
	if (stacks->stack_a_top != NULL)
		stack_step_back(&stacks->stack_a, stacks, skip);
	update_current_partition(stacks);
}
