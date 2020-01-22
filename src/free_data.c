/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artembykov <artembykov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:38:15 by artembykov        #+#    #+#             */
/*   Updated: 2020/01/22 18:48:12 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		free_partition_b(t_stacks *stacks)
{
	int i;

	i = -1;
	if (stacks->partitions)
	{
		while (++i < log2n(stacks->len_a) && stacks->partitions[i])
		{
			if (stacks->partitions[i] != NULL)
				free(stacks->partitions[i]);
		}
	}
	free(stacks->partitions);
}

void		free_stack(t_stack **stack)
{
	t_stack *tmp;

	if (stack && *stack)
	{
		while ((*stack))
		{
			tmp = *stack;
			*stack = (*stack)->next;
			free(tmp);
		}
	}
}

//static void		free_stack_visual(t_stacks *stacks)
//{
//	t_stack *tmp;
//
//	if (stacks->visual_stack)
//	{
//		while (stacks->visual_stack)
//		{
//			tmp = stacks->visual_stack;
//			stacks->visual_stack = stacks->visual_stack->next;
//			free(tmp);
//		}
//	}
//}

int				free_data(t_stacks *stacks)
{
//	free_stack(&stacks->stack_a);
//	free_stack(&stacks->visual_stack);
	free_partition_b(stacks);
	stacks->visual_please == 0 ? free(stacks->commands) : 0;
	stacks->unsorted_arr != NULL ? free(stacks->unsorted_arr) : 0;
	free(stacks);
	return (1);
}

int				print_error(t_stacks *stacks)
{
	free_data(stacks);
	ft_putstr("Error\n");
	return (1);
}
