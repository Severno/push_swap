#include "../includes/push_swap.h"


//int get_elems_num(t_stack *stack)
//{
//	t_stack *tmp;
//
//	tmp = stack;
//
//}

int true_median(t_stacks *stacks, t_stack *stack) {
	t_stack	*tmp_stack;
	int		arr[stacks->ac + 1];
	int		i;

	tmp_stack = stack;
	i = 0;
	while (tmp_stack)
	{
		arr[i] = tmp_stack->value;
		tmp_stack = tmp_stack->next;
		i++;
	}
	return quick_select(arr, 0, i - 1, i / 2);
}

int special_median(t_stacks *stacks, t_stack *stack) {
	t_stack	*tmp_stack;
	int		arr[stacks->ac + 1];
	int		i;

	tmp_stack = stack;
	i = 0;
	while (tmp_stack)
	{
		arr[i] = tmp_stack->value;
		tmp_stack = tmp_stack->next;
		i++;
	}
	return quick_select(arr, 0, i - 1, i / 2);
}