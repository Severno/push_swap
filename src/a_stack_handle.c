/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/15 16:15:48 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				is_sorted(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->next)
			if (stack_a->value > stack_a->next->value)
				return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void sort_three_elems_a(t_stack **a, t_stacks *stacks)
{
	int skip;
	int min;

	skip = 0;
	min = get_min_of_partition(stacks->stack_a,
								   stacks->stack_a_top);
	while ((*a)->value > min && (*a) != stacks->stack_a_top)
	{
		ft_apply_r(a, stacks);
		skip++;
	}
	if (is_sorted(stacks->stack_a))
		return;
	ft_apply_p(a, &stacks->stack_b, stacks);
	stack_step_back(&stacks->stack_a, stacks, skip);
	if ((*a)->value > (*a)->next->value)
		ft_apply_s(a, stacks);
	ft_apply_p(&stacks->stack_b, a, stacks);
	update_current_partition(stacks);
	stacks->stack_a_top = *a;
}

void sort_a(t_stack **a, t_stacks *stacks,  int capacity)
{
	if (capacity == 1)
		return ;
	if (capacity == 2) {
		if ((*a)->next->value < (*a)->value)
		{
			ft_apply_s(a, stacks);
			stacks->stack_a_top = *a;
		}
		return ;
	}
	sort_three_elems_a(a, stacks);
}

static int get_less_then_num_count(t_stack *stack, int median)
{
	int count;
	t_stack *tmp;

	count = 0;
	tmp = stack;
	if (!stack)
		return (0);
	while (tmp)
	{
		if (tmp->value <= median)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void push_less_than_median_to_b(t_stacks *stacks, int median) {
	int flag;
	int skip;
	int less_count;

	skip = 0;
	flag = 0;
	less_count = get_less_then_num_count(stacks->stack_a, median);
	stacks->partition_cap++;
	while (stacks->stack_a != stacks->stack_a_top && less_count > 0) {
		if (stacks->stack_a->value <= median) {
			ft_apply_p(&stacks->stack_a, &stacks->stack_b, stacks);
			if (flag == 0)
			{
				stacks->partitions[stacks->partition_cap]->end = stacks->stack_b;
				flag = 1;
			}
			less_count--;
			////print_stacks(stacks->stack_a, stacks->stack_b);
		} else {
			ft_apply_r(&stacks->stack_a, stacks);
			//print_stacks(stacks->stack_a, stacks->stack_b);
			skip++;
		}
	}
	stacks->partitions[stacks->partition_cap]->start = stacks->stack_b;
	if (stacks->stack_a_top != NULL)
		stack_step_back(&stacks->stack_a,stacks, skip);
	update_current_partition(stacks);
}
int get_elems_count_a(t_stack *stack, t_stacks *stacks)
{
	t_stack *tmp;
	int count;

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
//
//static int shift_rotate_four(t_stacks *stacks)
//{
//	int arr[4];
//	int min;
//	t_stack *tmp;
//	int steps;
//
//	tmp = stacks->stack_a;
//	steps = 0;
//	while (tmp)
//	{
//		if (tmp == stacks->stack_a_top)
//			break;
//		arr[steps] = tmp->value;
//		tmp = tmp->next;
//		steps++;
//	}
//	min = quick_select(arr, 0, steps, 2);
//	steps = 0;
//	tmp = stacks->stack_a;
//	while (tmp->value > min)
//	{
//		tmp = tmp->next;
//		steps++;
//	}
//	if (steps == 3)
//	{
//		while (--steps >= 2)
//		{
//			ft_apply_rr(&stacks->stack_a, stacks);
//			print_stacks(stacks->stack_a, stacks->stack_b);
//		}
//	}
//	else
//	{
//		steps = 0;
//		while (stacks->stack_a->value != min)
//		{
//
//			ft_apply_r(&stacks->stack_a, stacks);
//			print_stacks(stacks->stack_a, stacks->stack_b);
//			steps++;
//		}
////		stack_step_back(&stacks->stack_a, stacks, steps);
//	}
//	return (steps);
//}

//static void push_two_lowest(t_stack **from, t_stacks **to, int min, int min2)
//{
//	int counter;
//
//	counter = 0;
//	while (*stack)
//	{
//		if ((*stack)->value == min || (*stack)->value == min2)
//			ft_apply_p(from, to)
//	}
//}

//static void handle_four_elems_a(t_stacks *stacks)
//{
//	int steps;
//
//	if (is_sorted(stacks->stack_a))
//		return;
//	steps = shift_rotate_four(stacks);
//	print_stacks(stacks->stack_a, stacks->stack_b);
//	ft_apply_p(&stacks->stack_a, &stacks->stack_b, stacks);
//	stack_step_back(&stacks->stack_a, stacks, steps);
//	print_stacks(stacks->stack_a, stacks->stack_b);
//	sort_three_elems_a(&stacks->stack_a, stacks);
//	print_stacks(stacks->stack_a, stacks->stack_b);
//	ft_apply_p(&stacks->stack_b, &stacks->stack_a, stacks);
//	print_stacks(stacks->stack_a, stacks->stack_b);
//	stacks->stack_a_top = stacks->stack_a;
//}

//static void handle_five_elems_a(t_stacks *stacks)
//{
//	int arr[5];
//	int min;
//	int min2;
//	t_stack *tmp;
//	int steps;
//	int counter;
//
//	tmp = stacks->stack_a;
//	steps = 0;
//	counter = 0;
//	while (tmp)
//	{
//		arr[steps++] = tmp->value;
//		tmp = tmp->next;
//	}
//	min = quick_select(arr, 0, steps, 2);
//	min2 = quick_select(arr, 0, steps, 3);
//	steps = 0;
//	while (1)
//	{
//		if (counter == 2)
//			break;
//		if (stacks->stack_a->value == min || (stacks->stack_a->value == min2))
//		{
//			ft_apply_p(&stacks->stack_a, &stacks->stack_b, stacks);
//			counter++;
//		}
//		else
//		{
//			ft_apply_r(&stacks->stack_a, stacks);
//			steps++;
//		}
//	}
//	stack_step_back(&stacks->stack_a, stacks, steps);
//	sort_three_elems_a(&stacks->stack_a, stacks);
//	if (stacks->stack_b->value < stacks->stack_b->next->value)
//		ft_apply_s(&stacks->stack_b, stacks);
//	ft_apply_p(&stacks->stack_b, &stacks->stack_a, stacks);
//	ft_apply_p(&stacks->stack_b, &stacks->stack_a, stacks);
//	stacks->stack_a_top = stacks->stack_a;
//}

int a_to_b(t_stacks *stacks)
{
	int median;
	int elems_count;

	median = MAX_INTEGER;
	elems_count = get_elems_count_a(stacks->stack_a, stacks);
	if (elems_count <= 11 && elems_count > 3)
	{
		median = special_median_a(stacks);
//		printf("Special median A = %d\n", median); // 47 54 68 81 96 98
	}
	else if (elems_count > 11)
	{
		median = true_median(stacks, stacks->stack_a);
//		printf("TRUE median A = %d\n", median);
//		//print_stacks(stacks->stack_a, stacks->stack_b);
	}
	if (median != MAX_INTEGER)
	{
		push_less_than_median_to_b(stacks, median);
		//print_stacks(a, b, cmnd);
		//print_stacks(stacks->stack_a, stacks->stack_b);
//		printf("split_round_median median A = %d\n", median);
	}
	if (median == MAX_INTEGER)
	{
		sort_a(&stacks->stack_a, stacks, elems_count);
//		print_stacks(stacks->stack_a, stacks->stack_b);
	}
	if (median == MAX_INTEGER)
		stacks->stack_a_top = stacks->stack_a;
	print_stacks(stacks->stack_a, stacks->stack_b);
	return (median == MAX_INTEGER ? 0 : 1);
}