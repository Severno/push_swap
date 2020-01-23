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

void		check_commands(t_stacks *stacks)
{
	char	*buf;
	int		error;

	error = -1;
	while (get_next_line(0, &buf) > 0)
	{
		if (buf[0] == 'r')
			error = check_rotate_commands(stacks, buf, &stacks->stack_a);
		else if (buf[0] == 's' || buf[0] == 'p')
			error = check_push_swap_commands(stacks, buf, &stacks->stack_a);
		if (error == -1)
		{
			free(buf);
			exit(print_error(stacks));
		}
		error = -1;
		free(buf);
	}
}

static void	check_ko_ok_before_commands(t_stacks *stacks)
{
	if (stacks->len_a == 0)
		exit(0);
	if (is_sorted(stacks->stack_a)
	&& stacks->stack_b == NULL && stacks->stack_a)
	{
		ft_putstr("OK\n");
		exit(0);
	}
}

static void	check_ko_ok_after_commands(t_stacks *stacks)
{
	if (is_sorted(stacks->stack_a)
	&& stacks->stack_b == NULL && stacks->stack_a)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int			main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	stacks = create_stacks(argc, argv, CHECKER);
	stacks->checker_run = 1;
	if (stacks->stack_a == NULL
	|| has_duplicates(stacks->unsorted_arr, stacks->len_a))
		exit(print_error(stacks));
	check_ko_ok_before_commands(stacks);
	check_commands(stacks);
	check_ko_ok_after_commands(stacks);
	free_data(stacks);
	return (0);
}
