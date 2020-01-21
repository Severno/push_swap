/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:21:19 by sapril            #+#    #+#             */
/*   Updated: 2020/01/21 20:42:25 by artembykov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//static void print_line(int weight)
//{
//	int i;
//	int decades;
//	int hundreds;
//
//	i = weight;
//	decades = i / 10;
//	hundreds = i / 100;
//	while (--hundreds >= 0)
//	{
////		write(1, "____________________________________________________________________________________________________", 400);
//		write(1, "████████████████████████████████████████████████████████████████████████████████████████████████████", 300);
////		ft_putstr("████████████████████████████████████████████████████████████████████████████████████████████████████");
//		i -= 100;
//	}
//	while (--decades >= 0 && i / 10 > 0)
//	{
//		write(1, "██████████", 30);
////		ft_putstr("██████████");
//		i -= 10;
//	}
//	while (i >= 0)
//	{
//		if (i % 2 == 1)
//		{
//			write(1, "█", 3);
//			i--;
//		}
//		else
//		{
//			write(1, "██", 6);
//			i -= 2;
//		}
//	}
//}

static void print_line(int weight)
{
	int i;
	int decades;
	int hundreds;

	i = weight;
	decades = i / 10;
	hundreds = i / 100;
	while (--hundreds >= 0)
	{
//		write(1, "____________________________________________________________________________________________________", 400);
		write(1, "____________________________________________________________________________________________________", 100);
//		ft_putstr("████████████████████████████████████████████████████████████████████████████████████████████████████");
		i -= 100;
	}
	while (--decades >= 0 && i / 10 > 0)
	{
		write(1, "__________", 10);
//		ft_putstr("██████████");
		i -= 10;
	}
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
}

static void print_current_visual_state(t_stacks *stacks)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	ft_putstr(RED);
	tmp_a = stacks->visual_stack;
	tmp_b = stacks->stack_b;
	while (tmp_a != NULL) {
		print_line(tmp_a->weight);
		ft_putchar('\n');
		tmp_a = tmp_a->next;
	}
	ft_putstr(RESET);
	ft_putstr(CYAN);
	while (tmp_b != NULL)
	{
		print_line(tmp_b->weight);
		ft_putchar('\n');
		tmp_b = tmp_b->next;
	}
	ft_putstr(RESET);
}

static void update_current_visual_state(t_stacks *stacks, int i, char *split_commands)
{
//	write(1, WHITE "\n\n\n\n\n\n\n\n\n", 9);
//	write(1, "        ___  _  _ ____ _  _    ____ _ _ _ ____ ___        \n", 59);
//	write(1, RED "             STACK A is RED              \n", 43);
//	write(1, "        |__] |  | [__  |__| __ [__  | | | |__| |__]       ", 58);
//	write(1, CYAN "             STACK B is CYAN\n", 30);
//	write(1, "        |    |__| ___] |  |    ___] |_|_| |  | |         \n", 59);
//	write(1, RESET"", 0);
//	write(1, WHITE "\n\n\n\n\n\n\n\n\n", 9);
//	write(1, RESET"", 0);
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
	write(1, "Current operation: ",19);
	ft_putstr(split_commands);
	ft_putchar('\n');
	write(1, "Total: ",7);
	ft_putnbr(i + 1);
	ft_putchar('\n');
	usleep(25000);
}

void visual_commands(t_stacks *stacks)
{
	char **split_commands;
	int i;
	int operations;

	i = 0;
	operations = stacks->operations;
	split_commands = ft_strsplit(stacks->commands, '\n');
	print_current_visual_state(stacks);
	stacks->operations = 0;
	while (i < operations)
	{

		if (ft_strequ(split_commands[i], "sa"))
		{
			ft_apply_s(&stacks->visual_stack, stacks);
			update_current_visual_state(stacks, i, split_commands[i]);
		}
		else if (ft_strequ(split_commands[i], "sb"))
		{
			ft_apply_s(&stacks->stack_b, stacks);
			update_current_visual_state(stacks, i, split_commands[i]);
		}
		else if (ft_strequ(split_commands[i], "pa"))
		{
			ft_apply_p(&stacks->stack_b, &stacks->visual_stack, stacks);
			update_current_visual_state(stacks, i, split_commands[i]);
		}
		else if (ft_strequ(split_commands[i], "pb"))
		{
			ft_apply_p(&stacks->visual_stack, &stacks->stack_b, stacks);
			update_current_visual_state(stacks, i, split_commands[i]);
		}
		else if (ft_strequ(split_commands[i], "ra"))
		{
			ft_apply_r(&stacks->visual_stack, stacks);
			update_current_visual_state(stacks, i, split_commands[i]);
		}
		else if (ft_strequ(split_commands[i], "rb"))
		{
			ft_apply_r(&stacks->stack_b, stacks);
			update_current_visual_state(stacks, i, split_commands[i]);
		}
		else if (ft_strequ(split_commands[i], "rra"))
		{
			ft_apply_rr(&stacks->visual_stack, stacks);
			update_current_visual_state(stacks, i, split_commands[i]);
		}
		else if (ft_strequ(split_commands[i], "rrb"))
		{
			ft_apply_rr(&stacks->stack_b, stacks);
			update_current_visual_state(stacks, i, split_commands[i]);
		}
		else if (ft_strequ(split_commands[i], "rr"))
		{
			ft_apply_r_st(&stacks->visual_stack, &stacks->stack_b, stacks);
			update_current_visual_state(stacks, i, split_commands[i]);
		}
		else if (ft_strequ(split_commands[i], "rrr"))
		{
			ft_apply_rr_st(&stacks->visual_stack, &stacks->stack_b, stacks);
			update_current_visual_state(stacks, i, split_commands[i]);
		}
		i++;
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
	ft_quick_sort(arr, 0, stacks->len_a - 1);
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