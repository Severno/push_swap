/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 13:20:26 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_elems_count_a(t_stack *stack, t_stacks *stacks)
{
	t_stack		*tmp;
	int			count;

	count = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp != stacks->stack_a_top && tmp && count < 12)
		{
			tmp = tmp->next;
			count++;
		}
		return (count);
	}
	return (-1);
}

void	sort_a(t_stack **a, t_stacks *stacks, int capacity)
{
	if (capacity == 1)
		return ;
	if (capacity == 2)
	{
		if ((*a)->next->value < (*a)->value)
		{
			ft_apply_s(a, stacks);
			stacks->stack_a_top = *a;
		}
		return ;
	}
	sort_three_elems_a(a, stacks);
}

int		a_to_b(t_stacks *stacks)
{
	int median;
	int elems_count;

	median = NO_MEDIAN;
	elems_count = get_elems_count_a(stacks->stack_a, stacks);
	if (elems_count >= 3 && elems_count <= 6 && stacks->partition_cap == -1)
		handle_special_range(stacks);
	else if (elems_count <= 11 && elems_count > 3)
		median = special_median_a(stacks);
	else if (elems_count > 11)
		median = true_median(stacks, stacks->stack_a);
	if (median != NO_MEDIAN)
		push_less_than_median_to_b(stacks, median);
	if (median == NO_MEDIAN)
		sort_a(&stacks->stack_a, stacks, elems_count);
	if (median == NO_MEDIAN)
		stacks->stack_a_top = stacks->stack_a;
	return (median == NO_MEDIAN ? 0 : 1);
}
