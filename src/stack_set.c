/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 08:45:57 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 12:14:26 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *ft_create_new_stack_elem(int value)
{
	t_stack *new_elem;

	if (!(new_elem = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	new_elem->next = NULL;
	new_elem->prev = NULL;
	new_elem->value = value;
	return (new_elem);
}

void free_stack(t_stack **head)
{
	t_stack *tmp_begin_stack;

	while (*head)
	{
		tmp_begin_stack = *head;
		*head = (*head)->next;
		free(tmp_begin_stack);
	}
	*head = NULL;
	head = NULL;
}

void free_stacks(t_stacks *stacks)
{
	if (stacks->a_head)
		free_stack(&stacks->a_head);
	if (stacks->b_head)
		free_stack(&stacks->b_head);
	if (stacks->sorted_arr)
		free(stacks->sorted_arr);
	if (stacks->unsorted_arr)
		free(stacks->unsorted_arr);
//	if (stacks->poss_cur_range)
//		free(stacks->poss_cur_range);
	free(stacks);
}
