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

//sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
//		is only one or no elements).
//sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
//		is only one or no elements).
//ss : sa and sb at the same time.
//pa : push a - take the first element at the top of b and put it at the top of a. Do
//		nothing if b is empty.
//pb : push b - take the first element at the top of a and put it at the top of b. Do
//		nothing if a is empty.
//ra : rotate a - shift up all elements of stack a by 1. The first element becomes
//the last one.
//rb : rotate b - shift up all elements of stack b by 1. The first element becomes
//the last one.
//rr : ra and rb at the same time.
//rra : reverse rotate a - shift down all elements of stack a by 1. The last element
//		becomes the first one.
//8
//Push_swap Because Swap_push isn’t as natural
//		rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
//		becomes the first one.
//rrr : rra and rrb at the same time.

#include "../includes/push_swap.h"

int					ft_apply_s(t_stack **stack)
{
	int tmp_val;

	if (*stack && (*stack)->next)
	{
		tmp_val = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp_val;
		return (1);
	}
	return (0);
}
int					ft_apply_r(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_stack_push_back(stack, ft_stack_pop_back(stack));
		return (1);
	}
	return (0);
}
int					ft_apply_rr(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_stack_push_front(stack, ft_stack_pop_back(stack));
		return (1);
	}
	return (0);
}
//int					ft_apply_p(t_stack **from, t_stack **to)
//{
//
//}
//void				ft_apply_cnt(char *com, int cnt, t_stacks *sts)
//{
//
//}