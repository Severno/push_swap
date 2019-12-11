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

//t_stack		*create_stack(int capacity)
//{
//	t_stack *new_stack;
//
//	new_stack = NULL;
//	if ((new_stack = (t_stack *)ft_memalloc(sizeof(new_stack))))
//		exit(0);
//	new_stack->top = -1;
//	new_stack->max_size = capacity;
//	new_stack->items = (int *)ft_memalloc(sizeof(int) * capacity);
//	if (new_stack->items == NULL)
//		exit(0);
//	return (new_stack);
//}
//
//int			stack_size(t_stack *stack)
//{
//	return (stack->top + 1);
//}
//
//int			stack_is_empty(t_stack *stack)
//{
//	return (stack->top == -1);
//}