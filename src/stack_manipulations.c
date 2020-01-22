/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:36:24 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 15:36:43 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		stack_step_back(t_stack **stack, t_stacks *stacks, int skip)
{
	while (skip > 0)
	{
		ft_apply_rr(stack, stacks);
		skip--;
	}
}

void		update_current_partition(t_stacks *stacks)
{
	if (stacks->stack_b && stacks->partition_cap != -1)
	{
		stacks->partitions[stacks->partition_cap]->start = stacks->stack_b;
		if (stacks->partition_cap > 0)
			stacks->partitions[stacks->partition_cap]->end =
					stacks->partitions[stacks->partition_cap - 1]->start->prev;
		else
			stacks->partitions[stacks->partition_cap]->end =
					get_last_stack_elem(stacks->stack_b);
	}
}

int			push_more_than_median_b_rutine(t_stack **stack_b,
		t_stacks *stacks, int median, int *skip)
{
	if ((*stack_b)->value >= median)
		ft_apply_p(stack_b, &stacks->stack_a, stacks);
	else
	{
		ft_apply_r(stack_b, stacks);
		(*skip)++;
	}
	if ((*stack_b) == stacks->partitions[stacks->partition_cap]->end)
	{
		if ((*stack_b)->value >= median)
			ft_apply_p(stack_b, &stacks->stack_a, stacks);
		return (0);
	}
	return (1);
}
