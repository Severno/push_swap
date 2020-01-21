/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_special_case.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artembykov <artembykov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:10:30 by artembykov        #+#    #+#             */
/*   Updated: 2020/01/21 17:54:38 by artembykov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		push_and_rotate(t_stacks *stacks, int *arr,
		int stack_size, int *flag)
{
	if (check_is_equal_num(stacks->stack_a->value, arr, stack_size))
		ft_apply_p(&stacks->stack_a, &stacks->stack_b, stacks);
	else
		ft_apply_rr(&stacks->stack_a, stacks);
	if (*flag == 0)
		stacks->partitions[stacks->partition_cap]->end
		= stacks->stack_b;
	if (is_sorted(stacks->stack_a) && stacks->stack_b == NULL)
		return (0);
	*flag = 1;
	return (1);
}

static void		three_elems_command_checker(t_stacks *stacks,
		t_stack **stack)
{
	if (*stack == stacks->stack_a)
	{
		if ((*stack)->next->value > (*stack)->value)
			ft_apply_rr(stack, stacks);
		if ((*stack)->value > (*stack)->next->value
			&& (*stack)->value > (*stack)->next->next->value)
			ft_apply_r(stack, stacks);
		if ((*stack)->next->value < (*stack)->value)
			ft_apply_s(stack, stacks);
	}
	else
	{
		if ((*stack)->value > (*stack)->next->value)
			ft_apply_rr(stack, stacks);
		if ((*stack)->value < (*stack)->next->value &&
			(*stack)->value < (*stack)->next->next->value)
			ft_apply_r(stack, stacks);
		if ((*stack)->value < (*stack)->next->value)
			ft_apply_s(stack, stacks);
	}
}

void			fast_handle_only_three_elems(t_stack **stack,
		t_stacks *stacks)
{
	if (*stack == stacks->stack_a)
		while (!is_sorted(*stack))
			three_elems_command_checker(stacks, stack);
	else
		while (!is_rev_sorted(*stack))
			three_elems_command_checker(stacks, stack);
}

void		find_shortest_way_to_element_a(t_stacks *stacks)
{
	int counter;
	int arr[6];
	int stack_size;
	int flag;

	counter = 0;
	flag = 0;
	create_arr_from_linked_list(stacks->stack_a, arr, &counter);
	ft_bubble_sort(arr, counter);
	stack_size = get_stack_size(stacks->stack_a);
	stacks->partition_cap++;
	while (get_elems_count_a(stacks->stack_a, stacks) > 3)
		if (push_and_rotate(stacks, arr, stack_size, &flag) == 0)
			break;
	stacks->partitions[stacks->partition_cap]->start = stacks->stack_b;
}

void			handle_special_range(t_stacks *stacks)
{
	int b_elems;
	int a_elems;

	if (is_sorted(stacks->stack_a))
		return;
	find_shortest_way_to_element_a(stacks);
	a_elems = get_stack_size(stacks->stack_a);
	sort_a(&stacks->stack_a, stacks, a_elems);
	b_elems = get_stack_size(stacks->stack_b);
	sort_b(stacks, b_elems);
	push_b(stacks, &stacks->stack_b, b_elems);
	stacks->stack_a_top = stacks->stack_a;
}
