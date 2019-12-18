#include "../includes/push_swap.h"

// TODO
// Здесь содержится scanf его нужно на просто read переписать!!!!

void print_stacks(t_stack* stack_a, t_stack* stack_b)
{
	ft_printf(GREEN"\nStack A\n"RESET);
	while (stack_a != NULL) {
		ft_printf("%6d\n", stack_a->value);
		stack_a = stack_a->next;
	}

	ft_printf(BLUE"\nStack B\n"RESET);
	while (stack_b != NULL) {
		ft_printf("%6d\n", stack_b->value);
		stack_b = stack_b->next;
	}
}

void print_commands()
{
	ft_printf("CHOOSE COMMAND YOU LIKE:\n"
	RED"1. sa : swap a - swap the first 2 elements at the top of stack a\n"RESET
	RED"2. sb : swap b - swap the first 2 elements at the top of stack b\n"RESET
	RED"3. ss : sa and sb at the same time.\n"RESET
	RED"4. pa : push a - take the first element at the top of b and put it at the top of a.\n"RESET
	RED"5. pb : push b - take the first element at the top of a and put it at the top of b.\n"RESET
	RED"6. ra : rotate a - shift up all elements of stack a by 1.\n"RESET
	RED"7. rb : rotate b - shift up all elements of stack b by 1.\n"RESET
	RED"8. rr : ra and rb at the same time.\n"RESET
	RED"9. rra : reverse rotate a - shift down all elements of stack a by 1.\n"RESET
	RED"10. rrb : reverse rotate b - shift down all elements of stack b by 1.\n"RESET
	RED"11. rrr : rra and rrb at the same time.\n"RESET
	MAGENTA"IF YOU WANT SHOW COMMANDS AGAIN TYPE \"help\"\n"RESET);
}

void visualize_input_process(t_stacks *stacks)
{
	ft_printf("------------STARTING POSITION------------\n");
	print_commands();
	ft_print_int_arr(stacks->sorted_arr, 1, stacks->len_a - 1);
	print_stacks(stacks->stack_a, stacks->stack_b);
	ft_printf(RED"---------------------------------------------\nInput command:"RESET);
	while (1)
	{
		char buf[20];
		scanf ("%10s",buf); // TODO Здесь содержится scanf его нужно на просто read переписать!!!!
		if (ft_strequ(buf, "-1"))
			break;
		if (ft_strequ(buf, "sa"))
		{
			ft_apply_s(&stacks->stack_a);
			print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else if (ft_strequ(buf, "sb"))
		{
			ft_apply_s(&stacks->stack_b);
			print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else if (ft_strequ(buf, "pa"))
		{
			ft_apply_p(&stacks->stack_b, &stacks->stack_a);
			print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else if (ft_strequ(buf, "pb"))
		{
			ft_apply_p(&stacks->stack_a, &stacks->stack_b);
			print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else if (ft_strequ(buf, "ra"))
		{
			ft_apply_r(&stacks->stack_a);
			print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else if (ft_strequ(buf, "rb"))
		{
			ft_apply_r(&stacks->stack_b);
			print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else if (ft_strequ(buf, "rr"))
		{
			ft_apply_r_st(&stacks->stack_a, &stacks->stack_b);
			print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else if (ft_strequ(buf, "rra"))
		{
			ft_apply_rr(&stacks->stack_a);
			print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else if (ft_strequ(buf, "rrb"))
		{
			ft_apply_rr(&stacks->stack_b);
			print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else if (ft_strequ(buf, "rrr"))
		{
			ft_apply_rr_st(&stacks->stack_a, &stacks->stack_b);
			print_stacks(stacks->stack_a, stacks->stack_b);
		}
		else if (ft_strequ(buf, "help"))
		{
			print_commands();
		}
		ft_printf(RED"---------------------------------------------\nInput command:"RESET);
	}
}