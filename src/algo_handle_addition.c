//#include "../includes/push_swap.h"
//
//void compare_push_value_and_top_stack_b(t_stacks *stacks)
//{
//	while (1)
//	{
////		print_stacks(stacks->stack_a, stacks->stack_b);
//		if (stacks->stack_a->value < stacks->b_min && stacks->stack_b->value == stacks->b_max)
//			break;
//		else if (stacks->stack_a->value > stacks->stack_b->value && stacks->stack_b->value == stacks->b_max)
//			break;
//		else
//		{
//			find_correct_position(stacks);
//			break;
//		}
//	}
//}
//
//void push_a_to_sorted_b(t_stacks *stacks)
//{
//	if (stacks->stack_b == NULL || stacks->stack_b->next == NULL)
//	{
//		ft_apply_p(&stacks->stack_a, &stacks->stack_b);
//		stacks->sum_of_commands++;
//	}
//	else if (stacks->stack_b && stacks->stack_b->next)
//	{
//		stacks->b_max = get_max_b_value(stacks->stack_b);
//		stacks->b_min = get_min_b_value(stacks->stack_b);
//		if (stack_b_is_sorted(stacks))
//		{
////			print_stacks(stacks->stack_a, stacks->stack_b);
//			compare_push_value_and_top_stack_b(stacks);
//			ft_apply_p(&stacks->stack_a, &stacks->stack_b);
//			stacks->sum_of_commands++;
////			print_stacks(stacks->stack_a, stacks->stack_b);
//		}
//		else
//		{
////			print_stacks(stacks->stack_a, stacks->stack_b);
//			sort_stack_b(stacks);
//			compare_push_value_and_top_stack_b(stacks);
//			ft_apply_p(&stacks->stack_a, &stacks->stack_b);
//			stacks->sum_of_commands++;
////			print_stacks(stacks->stack_a, stacks->stack_b);
//		}
//	}
//}
//
//void push_all_b_to_a(t_stack **stack_a, t_stack **stack_b, t_stacks *stacks)
//{
//	while (*stack_b)
//	{
//		ft_apply_p(stack_b, stack_a);
//		stacks->sum_of_commands++;
//	}
//}
//
//void handle_one_chank(t_stacks *stacks)
//{
//	int cur_stack_pos;
//	int cur_range_pos;
//	t_stack *tmp_a;
//	int j;
//
//	j = 0;
//	cur_stack_pos = 0;
//	cur_range_pos = 0;
//	tmp_a = stacks->stack_a;
//	while (stacks->amount_found_pos > 0 && cur_range_pos < stacks->chank_range_len)
//	{
//		print_stacks(stacks->stack_a, stacks->stack_b);
//		if (cur_stack_pos == stacks->poss_cur_range[cur_range_pos])
//		{
//			cur_range_pos++;
//			stacks->amount_found_pos--;
//			while (j < cur_stack_pos)
//			{
////				print_stacks(stacks->stack_a, stacks->stack_b);
//				ft_apply_r(&stacks->stack_a);
//				stacks->sum_of_commands++;
//				j++;
////				print_stacks(stacks->stack_a, stacks->stack_b);
//				reduce_by_one(stacks, 0);
////				ft_print_int_arr(stacks->poss_cur_range, 1, stacks->chank_range_len);
//			}
//			cur_stack_pos = -1;
//			push_a_to_sorted_b(stacks);
//			reduce_by_one(stacks, 0);
////			print_stacks(stacks->stack_a, stacks->stack_b);
////			print_stacks(stacks->stack_a, stacks->stack_b);
////			ft_print_int_arr(stacks->poss_cur_range, 1, stacks->chank_range_len);
//		}
//		j = 0;
//		cur_stack_pos++;
//	}
//}