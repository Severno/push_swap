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

int get_middle_pos(int arr_size) // TODO переписать на size_t
{
	if (arr_size > 0)
		return ((arr_size - 1) / 2);
	else
		return (0);
}

t_stack *get_last_stack_elem(t_stack *stack)
{
	t_stack *tmp_stack;

	tmp_stack = stack;
	while (tmp_stack->next)
		tmp_stack = tmp_stack->next;
	return (tmp_stack);
}

int get_max_b_value(t_stack *stack_b)
{
	int max;
	t_stack *tmp_b;
	tmp_b = stack_b;
	max = tmp_b->value;
	while (tmp_b->next)
	{
		if (max < tmp_b->next->value)
			max = tmp_b->next->value;
		tmp_b = tmp_b->next;
	}
	return (max);
}

int get_min_b_value(t_stack *stack_b)
{
	int min;
	t_stack *tmp_b;
	tmp_b = stack_b;
	min = tmp_b->value;
	while (tmp_b->next)
	{
		if (min > tmp_b->next->value)
			min = tmp_b->next->value;
		tmp_b = tmp_b->next;
	}
	return (min);
}

size_t get_chank_range_len(t_stacks *stacks)
{
	return (stacks->len_a / stacks->chanks_amount);
}

int get_stack_size(t_stack *head)
{
	int size; // TODO перписать на size_t
	t_stack *current;

	size = 0;
	current = head;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

size_t get_chanks_num(size_t arr_size)
{
	if (arr_size >= 5 && arr_size <= 15)
		return (1);
	else if (arr_size >= 16 && arr_size <= 10000)
		return (2);
	else if (arr_size >= 31 && arr_size <= 50)
		return (8);
	else if (arr_size >= 51 && arr_size <= 100)
		return (10);
	else if ((arr_size >= 101 && arr_size <= 200))
		return (14);
	else if ((arr_size >= 201 && arr_size <= 500))
		return (18);
	else if ((arr_size >= 501 && arr_size <= 1000))
		return (20);
	else
		return (25);
}
