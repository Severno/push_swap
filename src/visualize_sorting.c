/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:21:19 by sapril            #+#    #+#             */
/*   Updated: 2020/01/19 01:17:06 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void print_line_a(int weight)
{
	int i;

	i = 0;
	while (i <= weight)
	{
		ft_putstr(RED"█"RESET);
		i++;
	}
}
static void print_line_b(int weight)
{
	int i;

	i = 0;
	while (i <= weight)
	{
		ft_putstr(MAGENTA"█"RESET);
		i++;
	}
}

static void print_current_visual_state(t_stacks *stacks)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
//	ft_printf(GREEN"\nStack A\n"RESET);
	tmp_a = stacks->visual_stack;
	tmp_b = stacks->stack_b;
	while (tmp_a != NULL) {
		print_line_a(tmp_a->weight);
		ft_putchar('\n');
		tmp_a = tmp_a->next;
	}
//	ft_printf(BLUE"\nStack B\n"RESET);
//	ft_printf("\033[%dA\33[2K\r\n", 3); // clear third line
	while (tmp_b != NULL)
	{
		print_line_b(tmp_b->weight);
		ft_putchar('\n');
		tmp_b = tmp_b->next;
	}
}

static void update_current_visual_state(t_stacks *stacks)
{
	int i;
	t_stack *tmp;

	i = stacks->len_a;
	tmp = stacks->stack_a;
		printf("\\e[1;1H\\e[2J");
//		ft_putstr(CLR);
		ft_putstr(WHITE "\n\n\n\n\n\n\n\n\n");
		ft_putstr("        ___  _  _ ____ _  _    ____ _ _ _ ____ ___        ");
		ft_putendl(CYAN "             STACK A is CYAN              ");
		ft_putstr("        |__] |  | [__  |__| __ [__  | | | |__| |__]       ");
		ft_putendl(MAGENTA "             STACK B is MAGENTA" RESET);
		ft_putendl("        |    |__| ___] |  |    ___] |_|_| |  | |         ");
		ft_putstr(RESET);
		ft_putstr(WHITE "\n\n\n\n\n");
		print_current_visual_state(stacks);
		ft_putstr(RESET);
//		usleep(100000);
//		printf("\033[10A\33[2K\r\n");
}

void clear_screen(t_stacks *stacks)
{
	int i;

	i = 0;
	while (i < stacks->len_a)
	{
		printf("\033[%dA\33[2K\r\n", i);
		i++;
	}
	i = 0;
	while (i < stacks->len_a)
	{
		printf("\033[%dB", i);
		i++;
	}
}

void sleep_ms(int milliseconds) // cross-platform sleep function
{
#ifdef WIN32
	Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
	struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
	usleep(milliseconds * 1000);
#endif
}

void visual_commands(t_stacks *stacks)
{
	char **split_commands;
	int i;

	i = 0;
	split_commands = ft_strsplit(stacks->commands, '\n');
	print_current_visual_state(stacks);
	while (i < stacks->operations) // TODO FIX SEGFAULT
	{

		if (ft_strequ(split_commands[i], "sa"))
		{
			ft_apply_s(&stacks->visual_stack, stacks);
			update_current_visual_state(stacks);
		}
		else if (ft_strequ(split_commands[i], "sb"))
		{
			ft_apply_s(&stacks->stack_b, stacks);
			update_current_visual_state(stacks);
		}
		else if (ft_strequ(split_commands[i], "pa"))
		{
			ft_apply_p(&stacks->stack_b, &stacks->visual_stack, stacks);
			update_current_visual_state(stacks);
		}
		else if (ft_strequ(split_commands[i], "pb"))
		{
			ft_apply_p(&stacks->visual_stack, &stacks->stack_b, stacks);
			update_current_visual_state(stacks);
		}
		else if (ft_strequ(split_commands[i], "ra"))
		{
			ft_apply_r(&stacks->visual_stack, stacks);
			update_current_visual_state(stacks);
		}
		else if (ft_strequ(split_commands[i], "rb"))
		{
			ft_apply_r(&stacks->stack_b, stacks);
			update_current_visual_state(stacks);
		}
		else if (ft_strequ(split_commands[i], "rra"))
		{
			ft_apply_rr(&stacks->visual_stack, stacks);
			update_current_visual_state(stacks);
		}
		else if (ft_strequ(split_commands[i], "rrb"))
		{
			ft_apply_rr(&stacks->stack_b, stacks);
			update_current_visual_state(stacks);
		}
		else if (ft_strequ(split_commands[i], "rr"))
		{
			ft_apply_r_st(&stacks->visual_stack, &stacks->stack_b, stacks);
			update_current_visual_state(stacks);
		}
		else if (ft_strequ(split_commands[i], "rrr"))
		{
			ft_apply_rr_st(&stacks->visual_stack, &stacks->stack_b, stacks);
			update_current_visual_state(stacks);
		}
		i++;
		sleep_ms(200);
//		clear_screen(stacks);
//		free(buf);
	}
}

static void set_value(t_stack *stack, int search_value, int *i)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == search_value)
		{
			tmp->weight = *i;
			return;
		}
		tmp = tmp->next;
	}
}

void set_weight_to_each_value(t_stacks *stacks) {
	t_stack *tmp;
	int arr[stacks->len_a + 1];
	int i;

	tmp = stacks->visual_stack;
	i = 0;
	while (tmp) {
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	tmp = stacks->visual_stack;
	i = 0;
	ft_bubble_sort(arr, stacks->len_a);
	while (i < stacks->len_a) {
		set_value(tmp, arr[i], &i);
		i++;
	}
}

void run_visualization(t_stacks *stacks)
{
	set_weight_to_each_value(stacks);
	visual_commands(stacks);
}