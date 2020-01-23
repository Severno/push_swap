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

void	visual_commands(t_stacks *stacks)
{
	char	**split_commands;
	int		i;
	int		operations;

	i = 0;
	split_commands = ft_strsplit(stacks->commands, '\n');
	operations = stacks->operations;
	stacks->operations = 0;
	while (i < operations)
	{
		if (split_commands[i][0] == 'r')
			check_rotate_commands(stacks,
					split_commands[i], &stacks->visual_stack);
		else
			check_push_swap_commands(stacks,
					split_commands[i], &stacks->visual_stack);
		usleep(20000);
		update_current_visual_state(stacks, i, split_commands[i]);
		i++;
	}
	free_split_str(&split_commands);
}
