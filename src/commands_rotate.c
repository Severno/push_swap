/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:12:01 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 15:12:33 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int					ft_apply_r(t_stack **stack, t_stacks *stacks)
{
	if (*stack && (*stack)->next)
	{
		if ((*stack) == stacks->stack_b)
			ft_strcat(stacks->commands, "rb\n");
		else
			ft_strcat(stacks->commands, "ra\n");
		stacks->operations++;
		ft_stack_push_back(stack, ft_stack_pop_front(stack));
		return (1);
	}
	return (0);
}

int					ft_apply_r_st(t_stack **stack_a,
		t_stack **stack_b, t_stacks *stacks)
{
	if (ft_apply_r(stack_a, stacks) && ft_apply_r(stack_b, stacks))
		return (1);
	return (0);
}

int					ft_apply_rr(t_stack **stack, t_stacks *stacks)
{
	if (*stack && (*stack)->next)
	{
		if ((*stack) == stacks->stack_b)
			ft_strcat(stacks->commands, "rrb\n");
		else
			ft_strcat(stacks->commands, "rra\n");
		stacks->operations++;
		ft_stack_push_front(stack, ft_stack_pop_back(stack));
		return (1);
	}
	return (0);
}

int					ft_apply_rr_st(t_stack **stack_a,
		t_stack **stack_b, t_stacks *stacks)
{
	if (ft_apply_rr(stack_a, stacks) && ft_apply_rr(stack_b, stacks))
		return (1);
	return (0);
}
