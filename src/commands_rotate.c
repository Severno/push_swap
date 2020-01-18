#include "../includes/push_swap.h"

int					ft_apply_r(t_stack **stack, t_stacks *stacks)
{
	char *tmp;

	if (*stack && (*stack)->next)
	{
		if ((*stack) == stacks->stack_b)
		{
			tmp = stacks->commands;
			stacks->commands = ft_strjoin(tmp, "rb\n");
			free(tmp);
		}
		else
		{
			tmp = stacks->commands;
			stacks->commands = ft_strjoin(tmp, "ra\n");
			free(tmp);
		}
		stacks->operations++;
		ft_stack_push_back(stack, ft_stack_pop_front(stack));
		return (1);
	}
	return (0);
}
int					ft_apply_r_st(t_stack **stack_a, t_stack **stack_b, t_stacks *stacks)
{
	if (ft_apply_r(stack_a, stacks) && ft_apply_r(stack_b, stacks))
		return (1);
	return (0);
}

int					ft_apply_rr(t_stack **stack, t_stacks *stacks)
{
	char *tmp;

	if (*stack && (*stack)->next)
	{
		if ((*stack) == stacks->stack_b)
		{
			tmp = stacks->commands;
			stacks->commands = ft_strjoin(tmp, "rrb\n");
			free(tmp);
		}
		else
		{
			tmp = stacks->commands;
			stacks->commands = ft_strjoin(tmp, "rra\n");
			free(tmp);
		}
		stacks->operations++;
		ft_stack_push_front(stack, ft_stack_pop_back(stack));
		return (1);
	}
	return (0);
}

int			ft_apply_rr_st(t_stack **stack_a, t_stack **stack_b, t_stacks *stacks)
{
	if (ft_apply_rr(stack_a, stacks) && ft_apply_rr(stack_b, stacks))
		return (1);
	return (0);
}