/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:07:18 by sapril            #+#    #+#             */
/*   Updated: 2019/12/09 15:09:30 by sapril           ###   ########.fr       */
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
