/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artembykov <artembykov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:38:15 by artembykov        #+#    #+#             */
/*   Updated: 2020/01/21 18:04:53 by artembykov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void 	free_partition_b(t_stacks *stacks)
{
	int i;

	i = 0;
	if (stacks->partitions)
	{
		while (i < log2n(stacks->len_a))
			free(stacks->partitions[i++]);
		free(stacks->partitions);
	}
}

static void		free_stack_a(t_stacks *stacks)
{
	t_stack *tmp;

	if (stacks->stack_a)
	{
		while (stacks->stack_a)
		{
			tmp = stacks->stack_a;
			stacks->stack_a = stacks->stack_a->next;
			free(tmp);
		}
	}
}

int				free_data(t_stacks *stacks)
{
	free_stack_a(stacks);
	free_partition_b(stacks);
	stacks->unsorted_arr != NULL ? free(stacks->unsorted_arr) : 0;
	stacks->commands != NULL ? free(stacks->commands) : 0;
	free(stacks);
	return (1);
}
