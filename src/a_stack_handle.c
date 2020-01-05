/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:04:28 by sapril            #+#    #+#             */
/*   Updated: 2020/01/05 15:46:45 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_tree_elems(t_stack **a)
{
	while ((*a)->next->next->value < (*a)->next->value && (*a)->next->value < (*a)->value)
	{
		if ((*a)->value <(*a)->next->value != 0 > (*a)->next->next->value)
		{
			ft_apply_r(a);
			ft_putstr("ra");
		}
		else {
			ft_apply_s(a);
			print_stacks(*a, *a);
			ft_putstr("sa");
			ft_apply_rr(a);
			print_stacks(*a, *a);
			ft_putstr("ra");
		}
	}
}

void sort_a(t_stack **a, int capacity)
{
	if (capacity == 1)
		return ;
	if (capacity == 2) {
		if ((*a)->next->value < (*a)->value) {
			ft_apply_s(a);
			ft_putstr("sa");
		}
		return;
	}
	sort_tree_elems(a);
}