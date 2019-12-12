/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:34 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 15:50:38 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static  void printList(t_stack* stack_a, t_stack* stack_b)
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


//	printf("\nTraversal in reverse direction \n");
//	while (last != NULL) {
//		printf(" %d ", last->value);
//		last = last->prev;
//	}
}

static void free_stack(t_stack **head)
{
	t_stack *tmp_begin_stack;

	while (*head)
	{
		tmp_begin_stack = *head;
		*head = (*head)->next;
		free(tmp_begin_stack);
	}
	*head = NULL;
	head = NULL;
}

static void free_stacks(t_stacks *stacks)
{
	if (stacks->a_head)
		free_stack(&stacks->a_head);
	if (stacks->b_head)
		free_stack(&stacks->b_head);
	if (stacks->sorted_arr)
		free(stacks->sorted_arr);
	if (stacks->unsorted_arr)
		free(stacks->unsorted_arr);
	free(stacks);
}

t_stack *ft_create_new_stack_elem(int value)
{
	t_stack *new_elem;

	if (!(new_elem = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	new_elem->next = NULL;
	new_elem->prev = NULL;
	new_elem->value = value;
	return (new_elem);
}

void append_stack_elem_to_end(t_stack **head, int value)
{
	t_stack *new_elem;
	t_stack *tail;

	new_elem = NULL;
	tail = ft_get_last_stack_elem(head);
	if (*head == NULL)
		*head = ft_create_new_stack_elem(value);
	else
	{
		new_elem = ft_create_new_stack_elem(value);
		new_elem->prev = tail;
		tail->next = new_elem;
	}

}

static void add_array_elems_to_stack_a(t_stacks *stacks)
{
	t_stack		*a_stack;
	int			i;

	i = 1;
	a_stack = ft_create_new_stack_elem(stacks->unsorted_arr[0]);
	while (i < stacks->len_a){
		ft_stack_push_back(&a_stack, ft_create_new_stack_elem(stacks->unsorted_arr[i++]));
//		ft_printf("%d\n", a_stack->next->value);
	}
	stacks->a_head = a_stack;
}

static void stacks_init(t_stacks **stacks, int *unsorted_arr, int array_size)
{
	*stacks = (t_stacks *)ft_memalloc(10000);
	(*stacks)->a_head = NULL;
	(*stacks)->a_tail = NULL;
	(*stacks)->b_head = NULL;
	(*stacks)->b_tail = NULL;
	(*stacks)->unsorted_arr = ft_copy_int_arr(unsorted_arr, array_size);
	(*stacks)->sorted_arr = ft_merge_sort(unsorted_arr, 0, array_size);
	(*stacks)->len_a = array_size;
	add_array_elems_to_stack_a(*stacks);
}

static void print_commands()
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

int main(int argc, char *argv[])
{
	t_stacks	*stacks;
	size_t		array_size;
	int			*unsorted_arr;

	array_size = 0;
	stacks = NULL;
	unsorted_arr = convert_str_to_int_array(argc, argv, &array_size);
	if (argc > 1)
	{
		stacks_init(&stacks, unsorted_arr, array_size);
		if (has_duplicates(stacks->unsorted_arr, stacks->len_a))
			print_error();
		else
			ft_merge_sort(stacks->sorted_arr, 0, stacks->len_a - 1);
	}
	else
		return (0);
	ft_printf("------------STARTING POSITION------------");
	print_commands();
	//sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
//		is only one or no elements).
//sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
//		is only one or no elements).
//ss : sa and sb at the same time.
//pa : push a - take the first element at the top of b and put it at the top of a. Do
//		nothing if b is empty.
//pb : push b - take the first element at the top of a and put it at the top of b. Do
//		nothing if a is empty.
//ra : rotate a - shift up all elements of stack a by 1. The first element becomes
//the last one.
//rb : rotate b - shift up all elements of stack b by 1. The first element becomes
//the last one.
//rr : ra and rb at the same time.
//rra : reverse rotate a - shift down all elements of stack a by 1. The last element
//		becomes the first one.
//8
//Push_swap Because Swap_push isn’t as natural
//		rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
//		becomes the first one.
//rrr : rra and rrb at the same time.
	printList(stacks->a_head, stacks->b_head);
	ft_printf(RED"---------------------------------------------\nInput command:"RESET);
	while (1)
	{
		char buf[20];
		scanf ("%10s",buf);
		if (ft_strequ(buf, "-1"))
			break;
		if (ft_strequ(buf, "sa"))
		{
			ft_apply_s(&stacks->a_head);
			printList(stacks->a_head, stacks->b_head);
		}
		else if (ft_strequ(buf, "pa"))
		{
			ft_apply_p(&stacks->a_head, &stacks->b_head);
			printList(stacks->a_head, stacks->b_head);
		}
		else if (ft_strequ(buf, "pb"))
		{
			ft_apply_p(&stacks->b_head, &stacks->a_head);
			printList(stacks->a_head, stacks->b_head);
		}
		else if (ft_strequ(buf, "ra"))
		{
			ft_apply_r(&stacks->a_head);
			printList(stacks->a_head, stacks->b_head);
		}
		else if (ft_strequ(buf, "rb"))
		{
			ft_apply_r(&stacks->a_head);
			printList(stacks->a_head, stacks->b_head);
		}
		else if (ft_strequ(buf, "rr"))
		{
			ft_apply_r_st(&stacks->a_head, &stacks->b_head);
			printList(stacks->a_head, stacks->b_head);
		}
		else if (ft_strequ(buf, "rra"))
		{
			ft_apply_rr(&stacks->a_head);
			printList(stacks->a_head, stacks->b_head);
		}
		else if (ft_strequ(buf, "rrb"))
		{
			ft_apply_rr(&stacks->b_head);
			printList(stacks->a_head, stacks->b_head);
		}
		else if (ft_strequ(buf, "rrr"))
		{
			ft_apply_rr_st(&stacks->a_head, &stacks->b_head);
			printList(stacks->a_head, stacks->b_head);
		}
		else if (ft_strequ(buf, "help"))
		{
			print_commands();
		}
		ft_printf(RED"---------------------------------------------\nInput command:"RESET);
	}
	free_stacks(stacks);
	return (0);
}