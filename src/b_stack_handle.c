/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 09:53:01 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_b(t_stacks *stacks, int capacity)
{
	t_stack *tmp;

	tmp = stacks->stack_b;
	if (tmp == NULL)
		return ;
	if (capacity == 1)
		return ;
	else if (capacity == 2)
	{
		if (stacks->stack_b->next->value > stacks->stack_b->value)
			ft_apply_s(&stacks->stack_b, stacks);
		return ;
	}
	sort_three_elems_b(stacks);
}

void		push_b(t_stacks *stacks,
		t_stack **stack_b, int capacity)
{
	int i;

	i = 0;
	capacity = (capacity == -1) ? 3 : capacity;
	while (i < capacity && stacks->stack_b)
	{
		ft_apply_p(stack_b, &stacks->stack_a, stacks);
		update_current_partition(stacks);
		if (stacks->partition_cap > 0 && stacks->stack_b
		== stacks->partitions[stacks->partition_cap - 1]->start)
		{
			stacks->partitions[stacks->partition_cap]->end = NULL;
			stacks->partitions[stacks->partition_cap]->start = NULL;
			stacks->partition_cap--;
		}
		i++;
	}
	update_current_partition(stacks);
}

int			b_to_a(t_stacks *stacks)
{
	int median;
	int elems_count;

	median = MAX_INTEGER;
	elems_count = get_elems_count_b(stacks);
	if (elems_count > 3)
		median = special_median_b(stacks);
	if (median != MAX_INTEGER)
		push_more_than_median_to_a(stacks, median);
	else
	{
		sort_b(stacks, elems_count);
		if (elems_count == 3)
			elems_count--;
	}
	if (median == MAX_INTEGER)
		push_b(stacks, &stacks->stack_b, elems_count);
	return (median == MAX_INTEGER ? 0 : 1);
}
