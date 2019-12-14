#include "../includes/push_swap.h"

int is_sorted(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->next)
		{
			if (stack_a->value > stack_a->next->value)
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

//static int *copy_current_find_range(t_stacks *stacks)
//{
//
//}
//
//static int roll_stack_up(t_stacks *stacks)
//{
//	(void)stacks;
//}
//
//static int roll_stack_down(t_stacks *stacks)
//{
//	(void)stacks;
//}


static int *get_poss_of_val_cur_range(t_stacks *stacks)
{
	int *poss_cur_range;
	t_stack *tmp_stack;
	int i;
	int	position;

	i = 0;
	position = 0;
	tmp_stack = stacks->a_head;
	poss_cur_range = (int *)ft_memalloc(sizeof(int) * stacks->chank_range_len);
	while (i < stacks->chank_range_len)
	{
		while (tmp_stack)
		{
			if (tmp_stack->value == stacks->sorted_arr[stacks->amount_found_pos])
			{
				poss_cur_range[stacks->amount_found_pos] = position;
				stacks->amount_found_pos++;
			}
			position++;
			tmp_stack = tmp_stack->next;
		}
		tmp_stack = stacks->a_head;
		position = 0;
		i++;
	}
	return (poss_cur_range);
}

static void reduce_by_one(t_stacks *stacks, int cur_range_pos)
{
	while (cur_range_pos < stacks->chank_range_len)
	{
		stacks->poss_cur_range[cur_range_pos] = stacks->poss_cur_range[cur_range_pos] - 1;
		cur_range_pos++;
	}
}


//static void swap_b_values(t_stack *less_val, t_stacks *stacks)
////{
////	while (less_val != stacks->b_head)
////	{
////		print_stacks(stacks->a_head, stacks->b_head);
////		ft_apply_r(&stacks->b_head);
////	}
////	ft_apply_s(&stacks->b_head);
////	print_stacks(stacks->a_head, stacks->b_head);
////}

static int stack_b_is_sorted(t_stacks *stacks)
{
	t_stack *tmp_b;

	tmp_b = stacks->b_head;
	while (tmp_b)
	{
		if (tmp_b->next)
		{
			if ((stacks->b_head->value == stacks->b_max
			&& get_last_stack_elem(stacks->b_head)->value == stacks->b_min))
				return (1);
			else if (tmp_b->value < tmp_b->next->value)
				return (0);
		}
		tmp_b = tmp_b->next;
	}
	return (1);
}

static void sort_stack_b(t_stacks *stacks)
{
	while (stack_b_is_sorted(stacks) == 0)
	{
//		print_stacks(stacks->a_head, stacks->b_head);
		ft_apply_r(&stacks->b_head);
//		print_stacks(stacks->a_head, stacks->b_head);
	}
}

static void find_correct_position(t_stacks *stacks)
{
	if (stacks->a_head->value < stacks->b_max)
	{
		while (stacks->a_head->value < stacks->b_head->value)
		{
			ft_apply_r(&stacks->b_head);
			stacks->sum_of_commands++;
		}
	}
}

static void compare_push_value_and_top_stack_b(t_stacks *stacks)
{
	while (1)
	{
//		print_stacks(stacks->a_head, stacks->b_head);
		if (stacks->a_head->value < stacks->b_min && stacks->b_head->value == stacks->b_max)
			break;
		else if (stacks->a_head->value > stacks->b_head->value && stacks->b_head->value == stacks->b_max)
			break;
		else
		{
			find_correct_position(stacks);
			break;
		}
	}
}

static void push_a_to_sorted_b(t_stacks *stacks)
{
	if (stacks->b_head == NULL || stacks->b_head->next == NULL)
	{
		ft_apply_p(&stacks->a_head, &stacks->b_head);
		stacks->sum_of_commands++;
	}
	else if (stacks->b_head && stacks->b_head->next)
	{
		stacks->b_max = get_max_b_value(stacks->b_head);
		stacks->b_min = get_min_b_value(stacks->b_head);
		if (stack_b_is_sorted(stacks))
		{
//			print_stacks(stacks->a_head, stacks->b_head);
			compare_push_value_and_top_stack_b(stacks);
			ft_apply_p(&stacks->a_head, &stacks->b_head);
			stacks->sum_of_commands++;
//			print_stacks(stacks->a_head, stacks->b_head);
		}
		else
		{
//			print_stacks(stacks->a_head, stacks->b_head);
			sort_stack_b(stacks);
			compare_push_value_and_top_stack_b(stacks);
			ft_apply_p(&stacks->a_head, &stacks->b_head);
			stacks->sum_of_commands++;
//			print_stacks(stacks->a_head, stacks->b_head);
		}
	}
}

static void push_all_b_to_a(t_stack **a_stack, t_stack **b_stack, t_stacks *stacks)
{
	while (*b_stack)
	{
		ft_apply_p(b_stack, a_stack);
		stacks->sum_of_commands++;
	}
}

static void handle_one_chank(t_stacks *stacks)
{
	int cur_stack_pos;
	int cur_range_pos;
	t_stack *tmp_a;
	int j;

	j = 0;
	cur_stack_pos = 0;
	cur_range_pos = 0;
	tmp_a = stacks->a_head;
	while (stacks->amount_found_pos > 0 && cur_range_pos < stacks->chank_range_len)
	{
		print_stacks(stacks->a_head, stacks->b_head);
		if (cur_stack_pos == stacks->poss_cur_range[cur_range_pos])
		{
			cur_range_pos++;
			stacks->amount_found_pos--;
			while (j < cur_stack_pos)
			{
//				print_stacks(stacks->a_head, stacks->b_head);
				ft_apply_r(&stacks->a_head);
				stacks->sum_of_commands++;
				j++;
//				print_stacks(stacks->a_head, stacks->b_head);
				reduce_by_one(stacks, 0);
//				ft_print_int_arr(stacks->poss_cur_range, 1, stacks->chank_range_len);
			}
			cur_stack_pos = -1;
			push_a_to_sorted_b(stacks);
			reduce_by_one(stacks, 0);
//			print_stacks(stacks->a_head, stacks->b_head);
//			print_stacks(stacks->a_head, stacks->b_head);
//			ft_print_int_arr(stacks->poss_cur_range, 1, stacks->chank_range_len);
		}
		j = 0;
		cur_stack_pos++;
	}
}

void ps_small_range(t_stacks *stacks)
{
	int i;

	i = 0;
	stacks->chanks_amount = stacks->len_a / 50;
	stacks->chank_range_len = get_chank_range_len(stacks);
//	ft_print_int_arr(stacks->poss_cur_range, 1, stacks->chank_range_len);
	while (i < stacks->chanks_amount)
	{
		stacks->poss_cur_range = get_poss_of_val_cur_range(stacks);
		ft_merge_sort(stacks->poss_cur_range, 0, stacks->chank_range_len - 1);
		handle_one_chank(stacks);
		stacks->b_max = get_max_b_value(stacks->b_head);
		stacks->b_min = get_min_b_value(stacks->b_head);
		sort_stack_b(stacks);
		i++;
	}
//	ft_printf("\n");
//	ft_print_int_arr(stacks->poss_cur_range, 1, stacks->chank_range_len);
//	ft_printf("\n");
//	ft_printf("Length: %d\n", stacks->len_a);
//	ft_printf("Middle: %d\n", stacks->middle_pos_a);
//	ft_print_int_arr(stacks->sorted_arr, 1, stacks->len_a);
//	ft_printf("\n");
//	print_positions_and_values_all_chanks(stacks);
//	print_stacks(stacks->a_head, stacks->b_head);

//	ft_printf(RED"Да, это примерно так выглядит\n"RESET);

	push_all_b_to_a(&stacks->a_head, &stacks->b_head, stacks);
	free(stacks->poss_cur_range);
}
void ps_middle_range(t_stacks *stacks)
{
	(void)stacks;
}
void ps_big_range(t_stacks *stacks)
{
	(void)stacks;
}

