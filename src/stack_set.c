/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 08:45:57 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 12:14:26 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *create_stack_a(t_stacks *stacks)
{
	t_stack		*stack_a;
	int			i;

	i = 1;
	stack_a = ft_create_new_stack_elem(stacks->unsorted_arr[0]);
	while (i < stacks->len_a)
		ft_stack_push_back(&stack_a, ft_create_new_stack_elem(stacks->unsorted_arr[i++]));
	return (stack_a);
}

t_stacks *create_stacks(int argc, char *argv[])
{
	t_stacks	*new_stacks;

	if (!(new_stacks = ft_memalloc(sizeof(t_stacks))))
		return (NULL);
	new_stacks->len_a = 0;
	new_stacks->unsorted_arr = convert_str_to_int_array(argc, argv, &new_stacks->len_a);
	new_stacks->sorted_arr = ft_copy_int_arr(new_stacks->unsorted_arr, new_stacks->len_a);
	new_stacks->stack_a = create_stack_a(new_stacks);
	new_stacks->stack_b = NULL;
	new_stacks->ac = argc;
	ft_merge_sort(new_stacks->sorted_arr, 0, new_stacks->len_a - 1);
	return (new_stacks);
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

void free_stack(t_stack **head)
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

int free_data(t_stacks *stacks)
{
	if (stacks->stack_a)
		free_stack(&stacks->stack_a);
	if (stacks->stack_b)
		free_stack(&stacks->stack_b);
	if (stacks->sorted_arr)
		free(stacks->sorted_arr);
	if (stacks->unsorted_arr)
		free(stacks->unsorted_arr);
//	if (stacks->poss_cur_range)
//		free(stacks->poss_cur_range);
	free(stacks);
	return (1);
}
