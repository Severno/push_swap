/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 08:45:57 by sapril            #+#    #+#             */
/*   Updated: 2020/01/18 22:46:18 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void create_stack_visual(t_stacks *stacks)
{
	int			i;

	i = 0;
	stacks->visual_stack = ft_create_new_stack_elem(stacks->unsorted_arr[i++]);
	while (i < stacks->len_a)
		ft_stack_push_back(&stacks->visual_stack, ft_create_new_stack_elem(stacks->unsorted_arr[i++]));
}

void create_stack_a(t_stacks *stacks)
{
	int			i;

	i = 0;
	stacks->stack_a = ft_create_new_stack_elem(stacks->unsorted_arr[i++]);
	while (i < stacks->len_a)
		ft_stack_push_back(&stacks->stack_a, ft_create_new_stack_elem(stacks->unsorted_arr[i++]));
}

static int log2n(unsigned int n)
{
	return (n > 1) ? 1 + log2n(n / 2) : 0;
}

t_stacks *create_stacks(int argc, char *argv[])
{
	t_stacks	*new_stacks;
	int i;

	i = -1;
	if (!(new_stacks = ft_memalloc(sizeof(t_stacks))))
		return (NULL);
	new_stacks->len_a = 0;
	new_stacks->partition_cap = -1;
	new_stacks->unsorted_arr = convert_str_to_int_array(argc, argv, &new_stacks->len_a);
	new_stacks->partitions = ft_memalloc(sizeof(t_part *) * (log2n(new_stacks->len_a)));
	new_stacks->commands = ft_strnew(3);
	while (++i < (log2n(new_stacks->len_a)))
		new_stacks->partitions[i] = ft_memalloc(sizeof(t_part));
	create_stack_a(new_stacks);
	create_stack_visual(new_stacks);
	new_stacks->stack_b = NULL;
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

int free_data(t_stacks *stacks)
{
	int i;
	t_stack *tmp;

	i = 0;
	if (stacks->partitions)
	{
		while (i < log2n(stacks->len_a))
		{
			free(stacks->partitions[i]);
			i++;
		}
		free(stacks->partitions);
	}
	if (stacks->stack_a)
	{
		while (stacks->stack_a)
		{
			tmp = stacks->stack_a;
			stacks->stack_a = stacks->stack_a->next;
			free(tmp);
		}
	}
	if (stacks->stack_b)
		free(stacks->stack_a);
	if (stacks->unsorted_arr)
		free(stacks->unsorted_arr);
	free(stacks);
	return (1);
}
