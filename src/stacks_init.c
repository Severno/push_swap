#include "../includes/push_swap.h"

void add_array_elems_to_stack_a(t_stacks *stacks)
{
	t_stack		*stack_a;
	int		i;

	i = 1;
	stack_a = ft_create_new_stack_elem(stacks->unsorted_arr[0]);
	while (i < stacks->len_a){
		ft_stack_push_back(&stack_a, ft_create_new_stack_elem(stacks->unsorted_arr[i++]));
//		ft_printf("%d\n", stack_a->next->value);
	}
	stacks->stack_a = stack_a;
}

void stacks_init(t_stacks **stacks, int *unsorted_arr, size_t array_size)
{
	*stacks = (t_stacks *)ft_memalloc(sizeof(t_stacks));
	(*stacks)->stack_a = NULL;
	(*stacks)->stack_b = NULL;
	(*stacks)->poss_cur_range = NULL;
	(*stacks)->amount_found_pos = 0;
	(*stacks)->chank_search_range = 0;
	(*stacks)->cur_range_min_val = MAX_LONG;
	(*stacks)->cur_range_max_val = MAX_LONG;
//	(*stacks)->current_num = MAX_LONG;
//	(*stacks)->cur_find_count = 0;
//	(*stacks)->cur_stack_pos = 0;
//	(*stacks)->cur_range_pos = 0;
//	(*stacks)->sorted_range_pos = 0;
	(*stacks)->unsorted_arr = ft_copy_int_arr(unsorted_arr, array_size);
	(*stacks)->sorted_arr = ft_merge_sort(unsorted_arr, 0, array_size - 1); // TODO поправить на size_t
	(*stacks)->len_a = array_size;
	(*stacks)->middle_pos_a = get_middle_pos((*stacks)->len_a);
	(*stacks)->chanks_amount = get_chanks_num(array_size);
	add_array_elems_to_stack_a(*stacks);
}