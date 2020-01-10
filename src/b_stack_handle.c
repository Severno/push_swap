#include "../includes/push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/10 18:29:25 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_tree_elems_b(t_stack **b, t_stacks *stacks)
{
	while ((*b)->next->next->value > (*b)->next->value && (*b)->next->value > (*b)->value)
	{
		if ((*b)->next->value < (*b)->next->next->value && (*b)->next->value < (*b)->value)
		{
			ft_apply_rr(b);
			ft_putstr("rrb");
		}
		else {
			ft_apply_r(b);
			ft_putstr("rb");
		}
	}
	ft_apply_s(b);
	ft_putstr("sb");
	stacks->stack_b_top = *b;
}

void sort_b(t_stack **b, t_stacks *stacks,  int capacity)
{
	if (capacity == 1)
		return ;
	if (capacity == 2) {
		if ((*b)->next->value < (*b)->value) {
			ft_apply_s(b);
			ft_putstr("sb");
			stacks->stack_a_top = *b;
		}
		return;
	}
	sort_tree_elems_b(b, stacks);
}

void push_sorted_b_to_a(t_stack **stack_b, t_stacks *stacks)
{
	int i;

	i = 0;
	while (i < 3)
	{
		ft_apply_p(stack_b, &stacks->stack_a);
		print_stacks(stacks->stack_a, *stack_b);
		ft_putstr("pa\n");
		i++;
	}
}
void push_less_than_median_to_a(t_stack *stack_b, t_stacks *stacks, int median)
{
	int top_value;

	top_value = stack_b->value;
	while (stack_b != stacks->stack_b_top)
	{
		if (stack_b->value <= median)
		{
			ft_apply_p(&stack_b, &stacks->stack_a);
			ft_putstr("pb\n");
		}
		else {
			ft_apply_r(&stack_b);
			print_stacks(stacks->stack_a, stack_b);
			ft_putstr("ra\n");
			if (stack_b->value == top_value)
				break;
		}
	}
}
int get_elems_count_b(t_stack *stack, t_stacks *stacks)
{
	t_stack *tmp;
	int count;

	tmp = stack;
	count = 0;
	if (tmp == NULL)
		return (-1);
	while (tmp != stacks->stack_b_top[stacks->partition_cap] && count < 12)
	{
		tmp = tmp->next;
		count++;
	}
	if (stacks->stack_b_top[stacks->partition_cap] && count == 3)
		return (-1);
	return (count);
}

int special_median_b(t_stack *b, t_stacks *stacks)
{

}
int b_to_a(t_stacks *stacks)
{
	int median;
	int elems_count;

	median = MAX_INTEGER;
	elems_count = get_elems_count_b(stacks->stack_b, stacks);
	return (median == MAX_INTEGER ? 0 : 1);
}