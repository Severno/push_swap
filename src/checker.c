/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:13:05 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 15:56:27 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_commands(t_stacks *stacks)
{
	char *buf;

	while (get_next_line(0, &buf) > 0)
	{
		if (buf[0] == 'r')
			check_rotate_commands(stacks, buf, &stacks->stack_a);
		else
			check_push_swap_commands(stacks, buf, &stacks->stack_a);
		free(buf);
	}
}

int		main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	stacks = create_stacks(argc, argv);
	if (stacks->stack_a == NULL
	|| has_duplicates(stacks->unsorted_arr, stacks->len_a))
		exit(free_data(stacks));
	check_commands(stacks);
	if (is_sorted(stacks->stack_a) && stacks->stack_b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_data(stacks);
	return (0);
}
