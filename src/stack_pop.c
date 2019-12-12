/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:37:57 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 14:24:15 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *ft_stack_pop_front(t_stack **stack)
{
	t_stack *tmp_stack;

	if (*stack == NULL)
		return (NULL);
	tmp_stack = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = tmp_stack->next;
	tmp_stack->next = NULL;
	return (tmp_stack);
}

t_stack		*ft_stack_pop_back(t_stack **stack)
{
	t_stack *before_last;
	t_stack *tmp;

	if (*stack == NULL)
		return (NULL);
	before_last = *stack;
	tmp = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		while (before_last->next && before_last->next->next)
			before_last = before_last->next;
		tmp = before_last->next;
		before_last->next = NULL;
	}
	return (tmp);
}