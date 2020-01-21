#include "../includes/push_swap.h"

int true_median(t_stacks *stacks, t_stack *stack) {
	t_stack	*tmp_stack;
	int		arr[stacks->len_a + 1];
	int		i;

	i = 0;
	if (stack != NULL)
	{
		tmp_stack = stack;
		while (tmp_stack != stacks->stack_a_top && tmp_stack)
		{
			arr[i] = tmp_stack->value;
			tmp_stack = tmp_stack->next;
			i++;
		}
		ft_quick_sort(arr, 0, i);
		return (arr[((i - 1) / 2)]);
	}
	return (0);
}

int special_median_a(t_stacks *stacks)
{
	t_stack	*tmp_stack;
	int		arr[stacks->len_a + 1];
	int		i;

	i = 0;
	if (stacks->stack_a != NULL)
	{
		tmp_stack = stacks->stack_a;
		while (tmp_stack != stacks->stack_a_top && tmp_stack)
		{
			arr[i] = tmp_stack->value;
			tmp_stack = tmp_stack->next;
			i++;
		}
		ft_quick_sort(arr, 0, i);
		return  (arr[((i - 1) / 2)]);
	}
	return (0);
}

int special_median_b(t_stacks *stacks)
{
	t_stack	*tmp_stack;
	int		arr[stacks->len_a + 1];
	int		i;

	i = 0;
	if (stacks->stack_b != NULL)
	{
		tmp_stack = stacks->stack_b;
		while ((tmp_stack != stacks->partitions[stacks->partition_cap]->end))
		{
			arr[i] = tmp_stack->value;
			tmp_stack = tmp_stack->next;
			i++;
		}
		ft_quick_sort(arr, 0, i);
		return  (arr[((i - 1) / 2)]);
	}
	return (0);
}
