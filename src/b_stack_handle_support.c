#include "../includes/push_swap.h"

int get_elems_count_b(t_stacks *stacks)
{
	t_stack *tmp;
	int count;

	if (stacks->stack_b == NULL)
		return (0);
	count = 1;
	tmp = stacks->stack_b;
	while (tmp != stacks->partitions[stacks->partition_cap]->end && tmp && count < 12)
	{
		count++;
		tmp = tmp->next;
	}
	if (!stacks->partitions[stacks->partition_cap]->end && count == 3)
		return (-1);
	return (count);
}

void		push_more_than_median_to_a(t_stacks *stacks, int median)
{
	int skip;

	skip = 0;
	while (stacks->stack_b && push_more_than_median_b_rutine(&stacks->stack_b, stacks, median, &skip))
		;
	stack_step_back(&stacks->stack_b, stacks, skip);
	update_current_partition(stacks);
}

void find_shortest_way_to_element(t_stacks *stacks, int max)
{
	t_stack *tmp;
	int counter;

	tmp = stacks->stack_b;
	counter = 0;
	while (tmp->value < max)
	{
		tmp = tmp->next;
		counter++;
	}
	if (counter == 2)
	{
		ft_apply_rr(&stacks->stack_b, stacks);
		ft_apply_p(&stacks->stack_b, &stacks->stack_a, stacks);
	}
	else
	{
		while (counter > 0)
		{
			ft_apply_r(&stacks->stack_b, stacks);
			counter--;
		}
		ft_apply_p(&stacks->stack_b, &stacks->stack_a, stacks);
	}
}

void sort_three_elems_b(t_stacks *stacks)
{
	int skip;
	int max;

	skip = 0;
	if (!stacks->stack_b)
		return;
	max = get_max_of_partition(stacks->partitions[stacks->partition_cap]->start,
									stacks->partitions[stacks->partition_cap]->end);
	if (get_stack_size(stacks->stack_b) == 3)
	{
		fast_handle_only_three_elems(&stacks->stack_b, stacks);
		return;
	}
	while ((stacks->stack_b)->value < max) {
		ft_apply_r(&stacks->stack_b, stacks);
		skip++;
	}
	ft_apply_p(&stacks->stack_b, &stacks->stack_a, stacks);
	update_current_partition(stacks);
	while (skip)
	{
		ft_apply_rr(&stacks->stack_b, stacks);
		update_current_partition(stacks);
		skip--;
	}
	if ((stacks->stack_b)->value < (stacks->stack_b)->next->value)
		ft_apply_s(&stacks->stack_b, stacks);
	update_current_partition(stacks);
}
