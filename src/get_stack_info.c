/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:45:02 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 10:55:20 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*get_last_stack_elem(t_stack *stack)
{
	t_stack *tmp_stack;

	tmp_stack = stack;
	while (tmp_stack->next)
		tmp_stack = tmp_stack->next;
	return (tmp_stack);
}

int			get_max_of_partition(t_stack *start, t_stack *end)
{
	t_stack	*tmp;
	int		max;

	tmp = start;
	max = start->value;
	while (tmp != end && tmp)
	{
		tmp = tmp->next;
		if (tmp != NULL && tmp->value > max)
			max = tmp->value;
	}
	return (max);
}

int			get_min_of_partition(t_stack *start, t_stack *end)
{
	t_stack	*tmp;
	int		min;

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

int			get_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		count;

	tmp = stack;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
