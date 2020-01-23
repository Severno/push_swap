/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:34 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 17:11:25 by sapril           ###   ########.fr       */
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
	stacks = create_stacks(argc, argv, PUSH_SWAP);
	if (stacks->stack_a == NULL
		|| has_duplicates(stacks->unsorted_arr, stacks->len_a))
		exit(print_error(stacks));
	if (is_sorted(stacks->stack_a) == 1)
		return (0);
	solver(stacks);
	ft_putstr(stacks->commands);
	stacks->input_process_please == 1 ? visualize_input_process(stacks) : 0;
	stacks->visual_please == 1 ? run_visualization(stacks) : 0;
	free_data(stacks);
	return (0);
}
