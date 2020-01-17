/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:07:18 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 13:37:28 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int					ft_apply_s(t_stack **stack, t_stacks *stacks)
{
	t_stack *tmp;

	if (*stack && (*stack)->next)
	{
		if ((*stack) == stacks->stack_b)
			ft_putstr("sb\n");
		else
			ft_putstr("sa\n");
		stacks->operations++;
		tmp = (*stack);
		(*stack) = (*stack)->next;
		tmp->next = (*stack)->next;
		tmp->prev = (*stack);
		(*stack)->next = tmp;
		(*stack)->prev = NULL;
		return (1);
	}
	return (0);
}

int					ft_apply_ss(t_stack **stack_a, t_stack **stack_b, t_stacks *stacks)
{
	if (ft_apply_s(stack_a, stacks) && ft_apply_s(stack_b, stacks))
		return (1);
	return (0);
}

int					ft_apply_p(t_stack **from, t_stack **to, t_stacks *stacks)
{
	t_stack *transfer_elem;

	if ((*from))
	{
		transfer_elem = ft_stack_pop_front(from);
		if ((*from) == stacks->stack_b)
			ft_putstr("pa\n");
		else
			ft_putstr("pb\n");
		stacks->operations++;
		if ((*to) == NULL)
		{
			(*to) = transfer_elem;
			return (1);
		}
		transfer_elem->next = (*to);
		(*to)->prev = transfer_elem;
		(*to) = transfer_elem;
		return (1);
	}
	return (0);
}
