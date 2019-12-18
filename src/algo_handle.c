#include "../includes/push_swap.h"

int		*get_poss_of_val_cur_range(t_stacks *stacks)
{
	int *poss_cur_range;
	t_stack *tmp_stack;
	int i;
	int	position;

	i = 0;
	position = 0;
	tmp_stack = stacks->stack_a;
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
		tmp_stack = stacks->stack_a;
		position = 0;
		i++;
	}
	return (poss_cur_range);
}

void reduce_by_one(t_stacks *stacks, int cur_range_pos)
{
	while (cur_range_pos < stacks->chank_range_len)
	{
		stacks->poss_cur_range[cur_range_pos] = stacks->poss_cur_range[cur_range_pos] - 1;
		cur_range_pos++;
	}
}

int stack_b_is_sorted(t_stacks *stacks)
{
	t_stack *tmp_b;

	tmp_b = stacks->stack_b;
	while (tmp_b)
	{
		if (tmp_b->next)
		{
			if ((stacks->stack_b->value == stacks->b_max
				 && get_last_stack_elem(stacks->stack_b)->value == stacks->b_min))
				return (1);
			else if (tmp_b->value < tmp_b->next->value)
				return (0);
		}
		tmp_b = tmp_b->next;
	}
	return (1);
}

void sort_stack_b(t_stacks *stacks)
{
	while (stack_b_is_sorted(stacks) == 0)
	{
//		print_stacks(stacks->stack_a, stacks->stack_b);
		ft_apply_r(&stacks->stack_b);
//		print_stacks(stacks->stack_a, stacks->stack_b);
	}
}

void find_correct_position(t_stacks *stacks)
{
	if (stacks->stack_a->value < stacks->b_max)
	{
		while (stacks->stack_a->value < stacks->stack_b->value)
		{
			ft_apply_r(&stacks->stack_b);
			stacks->sum_of_commands++;
		}
	}
}