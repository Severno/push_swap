#include "../includes/push_swap.h"

int					ft_apply_r(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_stack_push_back(stack, ft_stack_pop_front(stack));
		return (1);
	}
	return (0);
}
int					ft_apply_r_st(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_apply_r(stack_a) && ft_apply_r(stack_b))
		return (1);
	return (0);
}

int					ft_apply_rr(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_stack_push_front(stack, ft_stack_pop_back(stack));
		return (1);
	}
	return (0);
}

int					ft_apply_rr_st(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_apply_rr(stack_a) && ft_apply_rr(stack_b))
		return (1);
	return (0);
}