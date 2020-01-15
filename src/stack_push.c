/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:39:03 by sapril            #+#    #+#             */
/*   Updated: 2020/01/15 12:41:52 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *ft_get_last_stack_elem(t_stack **head)
{
	t_stack *tmp_head;

	tmp_head = *head;
	if (*head == NULL)
		return (NULL);
	while (tmp_head->next)
		tmp_head = tmp_head->next;
	return (tmp_head);
}

void ft_stack_push_back(t_stack **head, t_stack *target)
{
	t_stack *tail;


	tail = ft_get_last_stack_elem(head);
	if (*head == NULL)
		*head = target;
	else
	{
		tail->next = target;
		target->prev = tail;
	}
}

void ft_stack_push_front(t_stack **head, t_stack *target)
{
	t_stack *new_elem;

	new_elem = NULL;
	if (*head == NULL)
		*head = target;
	else
	{
		new_elem = target;
		new_elem->next = (*head);
		(*head)->prev = (new_elem);
		new_elem->prev = NULL;
		(*head) = new_elem;
	}
}