/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:13:05 by sapril            #+#    #+#             */
/*   Updated: 2020/01/18 22:16:01 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void check_commands(t_stacks *stacks)
{
	char *buf;

	while (get_next_line(0, &buf) > 0)
	{
		if (ft_strequ(buf, "sa"))
			ft_apply_s(&stacks->stack_a, stacks);
		else if (ft_strequ(buf, "sb"))
			ft_apply_s(&stacks->stack_b, stacks);
		else if (ft_strequ(buf, "pa"))
			ft_apply_p(&stacks->stack_b, &stacks->stack_a, stacks);
		else if (ft_strequ(buf, "pb"))
			ft_apply_p(&stacks->stack_a, &stacks->stack_b, stacks);
		else if (ft_strequ(buf, "ra"))
			ft_apply_r(&stacks->stack_a, stacks);
		else if (ft_strequ(buf, "rb"))
			ft_apply_r(&stacks->stack_b, stacks);
		else if (ft_strequ(buf, "rra"))
			ft_apply_rr(&stacks->stack_a, stacks);
		else if (ft_strequ(buf, "rrb"))
			ft_apply_rr(&stacks->stack_b, stacks);
		else if (ft_strequ(buf, "rr"))
			ft_apply_r_st(&stacks->stack_a, &stacks->stack_b, stacks);
		else if (ft_strequ(buf, "rrr"))
			ft_apply_rr_st(&stacks->stack_a, &stacks->stack_b, stacks);
		free(buf);
	}
}

int     main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	stacks = create_stacks(argc, argv);
	if (stacks->stack_a == NULL || has_duplicates(stacks->unsorted_arr, stacks->len_a))
		exit(free_data(stacks));
	check_commands(stacks);
//	print_stacks(stacks->stack_a, stacks->stack_b);
	if (is_sorted(stacks->stack_a) && stacks->stack_b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_data(stacks);
	return (0);
}