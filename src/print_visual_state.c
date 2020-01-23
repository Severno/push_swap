/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_visual_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:41:41 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 18:29:32 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_line(t_stack *stack)
{
	int i;

	while (stack != NULL)
	{
		i = stack->weight;
		i >= 100 ? hundred_loop(&i) : 0;
		i >= 10 ? ten_loop(&i) : 0;
		i >= 5 ? five_loop(&i) : 0;
		while (i >= 0)
		{
			if (i % 2 == 1 || i == 0)
			{
				write(1, "_", 1);
				i--;
			}
			else
			{
				write(1, "__", 2);
				i -= 2;
			}
		}
		ft_putchar('\n');
		ft_putchar('\n');
		stack = stack->next;
	}
}

void	print_current_visual_state(t_stacks *stacks)
{
	ft_putstr(RED);
	print_line(stacks->visual_stack);
	ft_putstr(RESET);
	ft_putstr(CYAN);
	print_line(stacks->stack_b);
	ft_putstr(RESET);
}

void	update_current_visual_state(t_stacks *stacks,
		int i, char *split_commands)
{
	(void)split_commands;
	(void)i;
	usleep(10000);
	ft_putstr(CLR);
	ft_putstr(WHITE "\n\n\n\n\n\n\n\n\n");
	ft_putstr("        ___  _  _ ____ _  _    ____ _ _ _ ____ ___        ");
	ft_putendl(RED "             STACK A is RED              ");
	ft_putstr("        |__] |  | [__  |__| __ [__  | | | |__| |__]       ");
	ft_putendl(CYAN "             STACK B is CYAN" RESET);
	ft_putendl("        |    |__| ___] |  |    ___] |_|_| |  | |         ");
	ft_putstr(RESET);
	ft_putstr(WHITE "\n\n\n\n\n\n\n\n\n");
	ft_putstr(RESET);
	print_current_visual_state(stacks);
	ft_printf("Current operation: %s\n"
	MAGENTA"Total: %d\n"RESET, split_commands, i + 1);
}
