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

static  void printList(t_stack* stack)
{
	t_stack *last;
	printf("\nTraversal in forward direction \n");
	while (stack != NULL) {
		printf(" %d ", stack->value);
		last = stack;
		stack = stack->next;
	}

	printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf(" %d ", last->value);
		last = last->prev;
	}
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
		append_stack_elem_to_end(&a_stack, stacks->unsorted_arr[i++]);
		ft_printf("%d\n", a_stack->value);
	}
}

static void stacks_init_params(t_stacks *stacks, int *unsorted_arr, int array_size)
{
	stacks->unsorted_arr = ft_copy_int_arr(unsorted_arr, array_size);
	stacks->sorted_arr = ft_merge_sort(unsorted_arr, 0, array_size);
	stacks->len_a = array_size;
	add_array_elems_to_stack_a(stacks);
}

static void stacks_init(t_stacks *stacks, int *unsorted_arr, int array_size)
{
	if (!(stacks = (t_stacks *)ft_memalloc(sizeof(stacks))))
		exit(1);
	stacks->a_head = NULL;
	stacks->a_tail = NULL;
	stacks->b_head = NULL;
	stacks->b_tail = NULL;
	stacks_init_params(stacks, unsorted_arr, array_size);
}


int main(int argc, char *argv[])
{
	t_stacks	*stacks;
	int			*unsorted_arr;
	size_t		array_size;

	array_size = 0;
	stacks = NULL;
	unsorted_arr = convert_str_to_int_array(argc, argv, &array_size);
	if (argc > 1)
	{
		stacks_init(stacks, unsorted_arr, array_size);
		if (has_duplicates(stacks->unsorted_arr, stacks->len_a))
			print_error(stacks->unsorted_arr);
		else
			ft_merge_sort(stacks->sorted_arr, 0, stacks->len_a - 1);
	}
	ft_apply_s(&stacks->a_head);
	ft_apply_r(&stacks->a_head);
	printList(stacks->a_head);
	free_stacks(stacks);
	return (0);
}