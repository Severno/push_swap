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

int get_middle_pos(int length)
{
	if (length > 0)
		return ((length - 1) / 2);
	else
		return (0);
}

int get_stack_size(t_stack *head)
{
	int size;
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
