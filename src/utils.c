/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artembykov <artembykov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:57:38 by artembykov        #+#    #+#             */
/*   Updated: 2020/01/21 16:20:42 by artembykov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				is_sorted(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->next)
			if (tmp->value > tmp->next->value)
				return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				is_rev_sorted(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				check_is_equal_num(int stack_value, int *arr, int len)
{
	int i;
	int border;

	i = 0;
	border = len - 3;
	while (i < border) {
		if (arr[i] == stack_value)
			return (1);
		i++;
	}
	return (0);
}

int				get_less_then_num_count(t_stack *stack, int median)
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

void create_arr_from_linked_list(t_stack *stack, int *arr, int *counter)
{
	while (stack)
	{
		arr[*counter] = stack->value;
		stack = stack->next;
		(*counter)++;
	}
}
