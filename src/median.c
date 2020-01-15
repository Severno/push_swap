#include "../includes/push_swap.h"


//int get_elems_num(t_stack *stack)
//{
//	t_stack *tmp;
//
//	tmp = stack;
//
//}

int true_median(t_stacks *stacks, t_stack *stack, int elems_count) {
	t_stack	*tmp_stack;
	int		arr[stacks->ac + 1];
	int		i;

	i = 0;
	if (stack != NULL)
	{
		tmp_stack = stack;
		while (tmp_stack)
		{
			arr[i] = tmp_stack->value;
			tmp_stack = tmp_stack->next;
			i++;
		}
		if (elems_count % 2 == 1)
			return quick_select(arr, 0,  i - 1, (i + 2) / 2);
		else
			return quick_select(arr, 0, i - 1, (i + 1) / 2);
	}
	return (0);
}

int special_median_a(t_stacks *stacks, int elems_count)
{
	t_stack	*tmp_stack;
	int		arr[stacks->ac + 1];
	int		i;

	i = 0;
	if (stacks->stack_a != NULL)
	{
		tmp_stack = stacks->stack_a;
		while (tmp_stack  && i < 12)
		{
			if (tmp_stack == stacks->stack_a_top)
			{
				i++;
				break;
			}
			arr[i] = tmp_stack->value;
			tmp_stack = tmp_stack->next;
			i++;
		}
		if (elems_count % 2 == 1)
			return quick_select(arr, 0,  i - 1, (i + 2) / 2);
		else
			return quick_select(arr, 0, i - 1, (i + 1) / 2);
	}
	return (0);
}

int special_median_b(t_stacks *stacks, int elems_count)
{
	t_stack	*tmp_stack;
	int		arr[stacks->ac + 1];
	int		i;

	i = 0;
	if (stacks->stack_b != NULL)
	{
		tmp_stack = stacks->stack_b;
		while (tmp_stack && i < 12)
		{
			if (tmp_stack == stacks->partitions[stacks->partition_cap]->end)
			{
				i++;
				break;
			}
			arr[i] = tmp_stack->value;
			tmp_stack = tmp_stack->next;
			i++;
		}
		if (elems_count % 2 == 1)
			return quick_select(arr, 0,  i - 1, (i + 2) / 2);
		else
			return quick_select(arr, 0, i - 1, (i + 1) / 2);
	}
	return (0);
}