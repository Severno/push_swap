/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 08:45:57 by sapril            #+#    #+#             */
/*   Updated: 2020/01/21 15:50:58 by artembykov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		create_stack(t_stacks *stacks, t_stack **stack)
{
	int i;

	i = 0;
	*stack = ft_create_new_stack_elem(stacks->unsorted_arr[i++]);
	while (i < stacks->len_a)
		ft_stack_push_back(stack,
		ft_create_new_stack_elem(stacks->unsorted_arr[i++]));
}

t_stacks	*create_stacks(int argc, char *argv[])
{
	t_stacks	*new_stk;
	int			i;

	i = -1;
	if (!(new_stk = ft_memalloc(sizeof(t_stacks))))
		return (NULL);
	new_stk->len_a = 0;
	new_stk->partition_cap = -1;
	new_stk->unsorted_arr =
	convert_str_to_int_array(argc, argv, &new_stk->len_a);
	new_stk->partitions = ft_memalloc(sizeof(t_part *)
			* (log2n(new_stk->len_a)));
	new_stk->commands = ft_strnew(25000); // TODO поправить выделяемую память, мб сделать ее динамической
	// в зависимоти от количества элементов
	while (++i < (log2n(new_stk->len_a)))
		new_stk->partitions[i] = ft_memalloc(sizeof(t_part));
	create_stack(new_stk, &new_stk->stack_a);
	create_stack(new_stk, &new_stk->visual_stack);
	new_stk->stack_b = NULL;
	return (new_stk);
}

t_stack		*ft_create_new_stack_elem(int value)
{
	t_stack *new_elem;

	if (!(new_elem = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return (NULL);
	new_elem->next = NULL;
	new_elem->prev = NULL;
	new_elem->value = value;
	return (new_elem);
}
