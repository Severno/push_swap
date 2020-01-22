/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_input_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:44:19 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 16:01:19 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_putchar('\n');
	ft_printf(GREEN"Stack A"RESET BLUE"         Stack B\n"RESET);
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a && stack_b)
			ft_printf("%6d      %6d", stack_a->value, stack_b->value);
		else if (stack_a)
			ft_printf("%6d      %6c", stack_a->value, ' ');
		else if (stack_b)
			ft_printf("%6c      %6d", ' ', stack_b->value);
		ft_putchar('\n');
		stack_a = stack_a != NULL ? stack_a->next : 0;
		stack_b = stack_b != NULL ? stack_b->next : 0;
	}
}

void			print_commands(t_stacks *stacks)
{
	ft_printf("------------STARTING POSITION------------\n");
	ft_printf("CHOOSE COMMAND YOU LIKE:\n"
	RED"1. sa : swap a - swap the first "
	"2 elements at the top of stack a\n"RESET
	RED"2. sb : swap b - swap the first "
	"2 elements at the top of stack b\n"RESET
	RED"3. ss : sa and sb at the same time.\n"RESET
	RED"4. pa : push a - take the first element "
	"at the top of b and put it at the top of a.\n"RESET
	RED"5. pb : push b - take the first element "
	"at the top of a and put it at the top of b.\n"RESET
	RED"6. ra : rotate a - shift up all elements of stack a by 1.\n"RESET
	RED"7. rb : rotate b - shift up all elements of stack b by 1.\n"RESET
	RED"8. rr : ra and rb at the same time.\n"RESET
	RED"9. rra : reverse rotate a - "
	"shift down all elements of stack a by 1.\n"RESET
	RED"10. rrb : reverse rotate b - "
	"shift down all elements of stack b by 1.\n"RESET
	RED"11. rrr : rra and rrb at the same time.\n"RESET
	MAGENTA"IF YOU WANT SHOW COMMANDS AGAIN TYPE \"help\"\n"RESET);
	print_stacks(stacks->visual_stack, stacks->stack_b);
	ft_printf(RED"------------------------"
			"---------------------\nInput command:"RESET);
}

void			check_rotate_commands(t_stacks *stacks,
		char *buf, t_stack **stack)
{
	if (ft_strequ(buf, "ra"))
		ft_apply_r(stack, stacks);
	else if (ft_strequ(buf, "rb"))
		ft_apply_r(&stacks->stack_b, stacks);
	else if (ft_strequ(buf, "rr"))
		ft_apply_r_st(stack, &stacks->stack_b, stacks);
	else if (ft_strequ(buf, "rra"))
		ft_apply_rr(stack, stacks);
	else if (ft_strequ(buf, "rrb"))
		ft_apply_rr(&stacks->stack_b, stacks);
	else if (ft_strequ(buf, "rrr"))
		ft_apply_rr_st(stack, &stacks->stack_b, stacks);
}

void			check_push_swap_commands(t_stacks *stacks,
		char *buf, t_stack **stack)
{
	if (ft_strequ(buf, "sa"))
		ft_apply_s(stack, stacks);
	else if (ft_strequ(buf, "sb"))
		ft_apply_s(&stacks->stack_b, stacks);
	else if (ft_strequ(buf, "pa"))
		ft_apply_p(&stacks->stack_b,
				stack, stacks);
	else if (ft_strequ(buf, "pb"))
		ft_apply_p(stack, &stacks->stack_b, stacks);
}

void			visualize_input_process(t_stacks *stacks)
{
	int		ret;
	char	buf[20];

	print_commands(stacks);
	while (1)
	{
		ret = read(0, buf, 20);
		buf[ret - 1] = '\0';
		if (ft_strequ(buf, "-1"))
			break ;
		if (buf[0] == 'r')
			check_rotate_commands(stacks, buf, &stacks->visual_stack);
		else if (ft_strequ(buf, "help"))
			print_commands(stacks);
		else
			check_push_swap_commands(stacks, buf, &stacks->visual_stack);
		print_stacks(stacks->visual_stack, stacks->stack_b);
		ft_printf(RED"-------------------------"
			"--------------------\nInput command:"RESET);
	}
}
