/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_visual_commands.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:42:57 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 18:24:12 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_commands(char *command, t_stacks *stacks)
{
	if (ft_strequ(command, "rb"))
		ft_apply_r(&stacks->stack_b, stacks);
	if (ft_strequ(command, "ra"))
		ft_apply_r(&stacks->visual_stack, stacks);
	else if (ft_strequ(command, "rra"))
		ft_apply_rr(&stacks->visual_stack, stacks);
	else if (ft_strequ(command, "rrb"))
		ft_apply_rr(&stacks->stack_b, stacks);
	else if (ft_strequ(command, "rr"))
		ft_apply_r_st(&stacks->visual_stack, &stacks->stack_b, stacks);
	else if (ft_strequ(command, "rrr"))
		ft_apply_rr_st(&stacks->visual_stack, &stacks->stack_b, stacks);
}

void	visual_commands(t_stacks *stacks)
{
	char	**split_commands;
	int		i;
	int		operations;

	i = 0;
	split_commands = ft_strsplit(stacks->commands, '\n');
	free(stacks->commands);
	operations = stacks->operations;
	stacks->operations = 0;
	while (i < operations)
	{
		if (split_commands[i][0] == 'r')
			rotate_commands(split_commands[i], stacks);
		else if (ft_strequ(split_commands[i], "sa"))
			ft_apply_s(&stacks->visual_stack, stacks);
		else if (ft_strequ(split_commands[i], "sb"))
			ft_apply_s(&stacks->stack_b, stacks);
		else if (ft_strequ(split_commands[i], "pa"))
			ft_apply_p(&stacks->stack_b, &stacks->visual_stack, stacks);
		else if (ft_strequ(split_commands[i], "pb"))
			ft_apply_p(&stacks->visual_stack, &stacks->stack_b, stacks);
		usleep(20000);
		update_current_visual_state(stacks, i, split_commands[i]);
		i++;
	}
//	free_split_str(&split_commands);
}
