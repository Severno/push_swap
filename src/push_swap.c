/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:34 by sapril            #+#    #+#             */
/*   Updated: 2020/01/21 18:08:48 by artembykov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			solver(t_stacks *stacks)
{
	int		sorted;

	while (!(sorted = is_sorted(stacks->stack_a))
	|| stacks->stack_b != NULL)
	{
		if (!sorted)
			while (a_to_b(stacks))
				;
		else
			stacks->stack_a_top = stacks->stack_a;
		b_to_a(stacks);
	}
	return (1);
}

int			main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	stacks = create_stacks(argc, argv);
	if (stacks->stack_a == NULL || is_sorted(stacks->stack_a) == 1
	|| has_duplicates(stacks->unsorted_arr, stacks->len_a))
		exit(free_data(stacks));
	solver(stacks);
	ft_putstr(stacks->commands);
//	run_visualization(stacks);
//	ft_printf(RED"Operations %d\n"RESET, stacks->operations);
	free_data(stacks);
	return (0);
}
