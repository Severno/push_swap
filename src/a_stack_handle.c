/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/10 20:39:29 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_tree_elems(t_stack **a, t_stacks *stacks)
{
	while ((*a)->next->next->value < (*a)->next->value && (*a)->next->value < (*a)->value)
	{
		if ((*a)->value <(*a)->next->value != 0 > (*a)->next->next->value)
		{
			ft_apply_r(a);
			ft_putstr("ra");
		}
		else {
			ft_apply_s(a);
			print_stacks(*a, *a);
			ft_putstr("sa");
			ft_apply_rr(a);
			print_stacks(*a, *a);
			ft_putstr("ra");
		}
	}
	stacks->stack_a_top = *a;
}

void sort_a(t_stack **a, t_stacks *stacks,  int capacity)
{
	if (capacity == 1)
		return ;
	if (capacity == 2) {
		if ((*a)->next->value < (*a)->value) {
			ft_apply_s(a);
			ft_putstr("sa");
			stacks->stack_a_top = *a;
		}
		return;
	}
	sort_tree_elems(a, stacks);
}

void push_less_than_median_to_b(t_stack *stack_a, t_stacks *stacks, int median)
{
	int top_value;

	top_value = stack_a->value;
	while (stack_a != stacks->stack_a_top)
	{
		if (stack_a->value <= median)
		{
			if (stack_a->value == median)
				stacks->stack_b_top[stacks->partition_cap++] = stack_a;
			ft_apply_p(&stack_a, &stacks->stack_b);
			ft_putstr("pb\n");
		}
		else {
			ft_apply_r(&stack_a);
			print_stacks(stack_a, stacks->stack_b);
			ft_putstr("ra\n");
			if (stack_a->value == top_value)
				break;
		}
	}
}
int get_elems_count_a(t_stack *stack, t_stacks *stacks)
{
	t_stack *tmp;
	int count;

	tmp = stack;
	count = 0;
	if (tmp == NULL)
		return (-1);
	while (tmp != stacks->stack_a_top && count < 12)
	{
		tmp = tmp->next;
		count++;
	}
	if (stacks->stack_a_top && count == 3)
		return (-1);
	return (count);
}
int a_to_b(t_stacks *stacks)
{
	int median;
	int elems_count;

	median = MAX_INTEGER;
	elems_count = get_elems_count_a(stacks->stack_a, stacks);
	if (elems_count == 3 && !is_sorted(stacks->stack_a))
		sort_a(&stacks->stack_a, stacks, elems_count);
	else if (elems_count <= 11 && elems_count > 2)
	{
		median = true_median(stacks, stacks->stack_a);
		printf("SPECIAL median A = %d\n", median);
	}
	else if (elems_count > 11)
	{
		median = true_median(stacks, stacks->stack_a);
		printf("TRUE median A = %d\n", median);
	}
	if (median != MAX_INTEGER)
	{
		push_less_than_median_to_b(stacks->stack_a, stacks, median);
	} else
		sort_a(&stacks->stack_a,stacks, elems_count);
	return (median == MAX_INTEGER ? 0 : 1);
}