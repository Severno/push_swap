/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/18 21:19:47 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				is_sorted(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->next)
			if (tmp->value > tmp->next->value)
				return (0);
		tmp = tmp->next;
	}
	return (1);
}

int is_rev_sorted(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void fast_handle_only_three_elems(t_stack **stack, t_stacks *stacks)
{
	if (*stack == stacks->stack_a)
	{
		while (!is_sorted(*stack))
		{
//			print_stacks(stacks->stack_a, stacks->stack_b);
			if ((*stack)->next->value > (*stack)->value)
				ft_apply_rr(stack, stacks);
//			print_stacks(stacks->stack_a, stacks->stack_b);
			if ((*stack)->value > (*stack)->next->value && (*stack)->value > (*stack)->next->next->value)
				ft_apply_r(stack, stacks);
//			print_stacks(stacks->stack_a, stacks->stack_b);
			if ((*stack)->next->value < (*stack)->value)
				ft_apply_s(stack, stacks);
//			print_stacks(stacks->stack_a, stacks->stack_b);
		}
	}
	else
	{
		while (!is_rev_sorted(*stack))
		{
//			print_stacks(stacks->stack_a, stacks->stack_b);
			if ((*stack)->value > (*stack)->next->value)
				ft_apply_rr(stack, stacks);
//			print_stacks(stacks->stack_a, stacks->stack_b);
			if ((*stack)->value < (*stack)->next->value && (*stack)->value < (*stack)->next->next->value)
				ft_apply_r(stack, stacks);
//			print_stacks(stacks->stack_a, stacks->stack_b);
			if ((*stack)->value < (*stack)->next->value)
				ft_apply_s(stack, stacks);
//			print_stacks(stacks->stack_a, stacks->stack_b);
		}
	}

}

void sort_three_elems_a(t_stack **a, t_stacks *stacks)
{
//	int skip;
//	int min;
//
//	skip = 0;
//	min = get_min_of_partition(stacks->stack_a,
//							   stacks->stack_a_top);
//
//	if (get_elems_count_a(stacks->stack_a, stacks) == 3)
//		if ((*a)->value > (*a)->next->value)
//			ft_apply_s(a, stacks);
////	find_shortest_way_to_element_a(stacks);
//	while ((*a)->value > min && (*a) != stacks->stack_a_top)
//	{
//		ft_apply_r(a, stacks);
//		skip++;
//	}
//	if (is_sorted(stacks->stack_a))
//		return;
//
////	ft_apply_p(a, &stacks->stack_b, stacks);
//	stack_step_back(&stacks->stack_a, stacks, skip);
//	if ((*a)->value > (*a)->next->value)
//		ft_apply_s(a, stacks);
//	ft_apply_p(&stacks->stack_b, a, stacks);
//	update_current_partition(stacks);
//	stacks->stack_a_top = *a;

	int skip;
	int min;

	skip = 0;
	min = get_min_of_partition(stacks->stack_a,
							   stacks->stack_a_top);
	if (get_stack_size(*a) == 3 && get_stack_size(stacks->stack_b) < 4)
	{
		fast_handle_only_three_elems(a, stacks);
		return;
	}
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
//		if (tmp == stacks->stack_a_top)
//			break;
//		arr[steps] = tmp->value;
//		tmp = tmp->next;
//		steps++;
//	}
//	ft_bubble_sort(arr, 4);
//	min = arr[0];
//	min2 = arr[1];
//	steps = 0;
//	tmp = stacks->stack_a;
//	while (counter != 2)
//	{
//		if (stacks->stack_a->value == min || stacks->stack_a->value == min2)
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
//	while (steps > 0 && stacks->partition_cap != -1)
//	{
//		ft_apply_rr(&stacks->stack_a, stacks);
//		steps--;
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

//static int shift_rotate_five(t_stacks *stacks)
//{
//	int arr[5];
//	int min;
//	int min2;
//	int min3;
//	t_stack *tmp;
//	int steps;
//	int counter;
//	int flag;
//
//	tmp = stacks->stack_a;
//	steps = 0;
//	counter = 0;
//	flag = 0;
//	while (tmp)
//	{
//		if (tmp == stacks->stack_a_top)
//			break;
//		arr[steps] = tmp->value;
//		tmp = tmp->next;
//		steps++;
//	}
//	ft_bubble_sort(arr, 5);
//	min = arr[0];
//	min2 = arr[1];
//	min3 = arr[2];
//	steps = 0;
//	tmp = stacks->stack_a;
//	stacks->partition_cap++;
//	while (counter != 3)
//	{
//		if (stacks->stack_a->value == min || stacks->stack_a->value == min2 || stacks->stack_a->value == min3)
//		{
//			ft_apply_p(&stacks->stack_a, &stacks->stack_b, stacks);
//			counter++;
//			if (flag == 0)
//			{
//				stacks->partitions[stacks->partition_cap]->end = stacks->stack_b;
//				flag = 1;
//			}
//		}
//		else
//		{
//			ft_apply_r(&stacks->stack_a, stacks);
//			steps++;
//		}
//	}
//	stacks->partitions[stacks->partition_cap]->start = stacks->stack_b;
//	while (steps > 0 && stacks->stack_a_top != NULL)
//	{
//		ft_apply_rr(&stacks->stack_a, stacks);
//		steps--;
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

int check_is_equal_num(int stack_value, int *arr, int len)
{
	int i;
	int border;

	i = 0;
	border = len - 3;
	while (i < border) {
		if (arr[i] == stack_value)
			return (1);
		i++;
	}
	return (0);
}


void find_shortest_way_to_element_a(t_stacks *stacks)
{
	t_stack *tmp;
	int counter;
	int arr[6];
	int stack_size;
	int flag;

	tmp = stacks->stack_a;
	counter = 0;
	flag = 0;
	while (tmp)
	{
		arr[counter] = tmp->value;
		tmp = tmp->next;
		counter++;
	}
	ft_bubble_sort(arr, counter);
//	ft_quick_sort(arr, 0, counter);
	counter = 0;
	stack_size = get_stack_size(stacks->stack_a);
	tmp = stacks->stack_a;
	stacks->partition_cap++;
	while (get_elems_count_a(stacks->stack_a, stacks) > 3)
	{
		if (check_is_equal_num(stacks->stack_a->value, arr, stack_size))
			ft_apply_p(&stacks->stack_a, &stacks->stack_b, stacks);
		else
			ft_apply_rr(&stacks->stack_a, stacks);
		if (flag == 0)
			stacks->partitions[stacks->partition_cap]->end = stacks->stack_b;
		if (is_sorted(stacks->stack_a) && stacks->stack_b == NULL)
			break;
//		print_stacks(stacks->stack_a, stacks->stack_b);
		flag = 1;
	}
	stacks->partitions[stacks->partition_cap]->start = stacks->stack_b;
}

void handle_special_range(t_stacks *stacks)
{
	int b_elems;
	int a_elems;
	if (is_sorted(stacks->stack_a))
		return;
	find_shortest_way_to_element_a(stacks);
	a_elems = get_stack_size(stacks->stack_a);
//	print_stacks(stacks->stack_a, stacks->stack_b);
	sort_a(&stacks->stack_a, stacks, a_elems);
//	print_stacks(stacks->stack_a, stacks->stack_b);
	b_elems = get_stack_size(stacks->stack_b);
	sort_b(stacks, b_elems);
//	print_stacks(stacks->stack_a, stacks->stack_b);
	push_b(stacks, &stacks->stack_b, b_elems);
	stacks->stack_a_top = stacks->stack_a;
}

void handle_five_elems_a(t_stacks *stacks)
{
	int b_elems;
	if (is_sorted(stacks->stack_a))
		return;
	find_shortest_way_to_element_a(stacks);
//	print_stacks(stacks->stack_a, stacks->stack_b);
	sort_a(&stacks->stack_a, stacks, 2);
//	print_stacks(stacks->stack_a, stacks->stack_b);
	b_elems = get_elems_count_b(stacks);
	sort_b(stacks, b_elems);
//	print_stacks(stacks->stack_a, stacks->stack_b);
	push_b(stacks, &stacks->stack_b, b_elems);
	stacks->stack_a_top = stacks->stack_a;
}

void handle_four_elems_a(t_stacks *stacks)
{
	if (is_sorted(stacks->stack_a))
		return;
	find_shortest_way_to_element_a(stacks);
//	print_stacks(stacks->stack_a, stacks->stack_b);
	sort_a(&stacks->stack_a, stacks, 2);
//	print_stacks(stacks->stack_a, stacks->stack_b);
	push_b(stacks, &stacks->stack_b, 1);
//	print_stacks(stacks->stack_a, stacks->stack_b);
	stacks->stack_a_top = stacks->stack_a;
}

//int a_to_b(t_stacks *stacks)
//{
//	int median;
//	int elems_count;
//
//	median = MAX_INTEGER;
//	elems_count = get_elems_count_a(stacks->stack_a, stacks);
//	if (elems_count <= 11 && elems_count > 3)
//	{
//		median = special_median_a(stacks);
////		printf("Special median A = %d\n", median); // 47 54 68 81 96 98
//	}
//	else if (elems_count > 11)
//	{
//		median = true_median(stacks, stacks->stack_a);
////		printf("TRUE median A = %d\n", median);
////		//print_stacks(stacks->stack_a, stacks->stack_b);
//	}
//
//	if (median != MAX_INTEGER)
//	{
//		push_less_than_median_to_b(stacks, median);
//		//print_stacks(a, b, cmnd);
//		//print_stacks(stacks->stack_a, stacks->stack_b);
////		printf("split_round_median median A = %d\n", median);
//	}
//	if (median == MAX_INTEGER)
//	{
//		sort_a(&stacks->stack_a, stacks, elems_count);
////		print_stacks(stacks->stack_a, stacks->stack_b);
//	}
//	if (median == MAX_INTEGER)
//		stacks->stack_a_top = stacks->stack_a;
////	print_stacks(stacks->stack_a, stacks->stack_b);
//	return (median == MAX_INTEGER ? 0 : 1);
//}

int a_to_b(t_stacks *stacks)
{
	int median;
	int elems_count;

	median = MAX_INTEGER;
	elems_count = get_elems_count_a(stacks->stack_a, stacks);
	if (elems_count >= 3 && elems_count <= 6 && stacks->partition_cap == -1)
		handle_special_range(stacks);
	else if (elems_count <= 11 && elems_count > 3)
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
//	print_stacks(stacks->stack_a, stacks->stack_b);
	return (median == MAX_INTEGER ? 0 : 1);
}