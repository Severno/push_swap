#include "../includes/push_swap.h"


//
////static void swap_b_values(t_stack *less_val, t_stacks *stacks)
//////{
//////	while (less_val != stacks->stack_b)
//////	{
//////		print_stacks(stacks->stack_a, stacks->stack_b);
//////		ft_apply_r(&stacks->stack_b);
//////	}
//////	ft_apply_s(&stacks->stack_b);
//////	print_stacks(stacks->stack_a, stacks->stack_b);
//////}
//
//
//void ps_small_range(t_stacks *stacks)
//{
//	int i;
//	int j;
//	t_stack *a_tmp;
//	t_stack *b_tmp;
//
//	i = 0;
//	j = 0;
//	a_tmp = stacks->stack_a;
//	b_tmp = stacks->stack_b;
//	stacks->chanks_amount = 1;
//	stacks->chank_range_len = get_chank_range_len(stacks);
////	ft_print_int_arr(stacks->poss_cur_range, 1, stacks->chank_range_len);
//
//// ----------BRUTFORCE-----------
////	while (j < stacks->len_a)
////	{
////		while (1)
////		{
////			if (stacks->stack_a->value == stacks->sorted_arr[j])
////			{
////				ft_apply_p(&stacks->stack_a, &stacks->stack_b);
////				stacks->sum_of_commands++;
////				break;
////			}
////			ft_apply_r(&stacks->stack_a);
////			stacks->sum_of_commands++;
////		}
////		j++;
////	}
////	push_all_b_to_a(&stacks->stack_a, &stacks->stack_b, stacks);
//// ----------BRUTFORCE END-----------
//	while (i < stacks->chanks_amount)
//	{
//		stacks->poss_cur_range = get_poss_of_val_cur_range(stacks);
//		ft_merge_sort(stacks->poss_cur_range, 0, stacks->chank_range_len - 1);
//		handle_one_chank(stacks);
//		stacks->b_max = get_max_b_value(stacks->stack_b);
//		stacks->b_min = get_min_b_value(stacks->stack_b);
//		sort_stack_b(stacks);
//		i++;
//	}
//	push_all_b_to_a(&stacks->stack_a, &stacks->stack_b, stacks);
////	ft_printf("\n");
////	ft_print_int_arr(stacks->poss_cur_range, 1, stacks->chank_range_len);
////	ft_printf("\n");
////	ft_printf("Length: %d\n", stacks->len_a);
////	ft_printf("Middle: %d\n", stacks->middle_pos_a);
////	ft_print_int_arr(stacks->sorted_arr, 1, stacks->len_a);
////	ft_printf("\n");
////	print_positions_and_values_all_chanks(stacks);
////	print_stacks(stacks->stack_a, stacks->stack_b);
//
////	ft_printf(RED"Да, это примерно так выглядит\n"RESET);
//
//	free(stacks->poss_cur_range);
//}
//
//void ps_middle_range(t_stacks *stacks)
//{
//	(void)stacks;
//}
//void ps_big_range(t_stacks *stacks)
//{
//	(void)stacks;
//}
//
//
////static int		range_pos_funct(t_stack *a, int local_max)
////{
////	int pos_num;
////	int i;
////
////	pos_num = 0;
////	i = -1;
////	while (a)
////	{
////		i++;
////		if (a->value <= local_max)
////		{
////			return (i);
////		}
////		a = a->next;
////	}
////	return (i);
////}
//
//// COMPARE IMPLEMENTATION
////int		bulky_med(t_stack **a, t_stack **b, int i, t_stacks *stacks)
////{
////	int local_max;
////	int	elems;
////	int j;
////	int tot_div_chunk;
////	int range_pos;
////
////	j = 0;
////	elems = get_number_of_elements(stacks->stack_a);
////	while (*a)
////	{
////		j++;
////		local_max = elems / 5;
////		tot_div_chunk = local_max * j;
////		range_pos = range_pos_funct(*a, local_max);
////		if (range(*a, tot_div_chunk) == 1)
////			i += a_handle_while_range(a, b, range_pos, tot_div_chunk);
////	}
////	if (!*a)
////		i += rb_or_rrb_one_hundered(a, b, elems);
////	return (i);
////}