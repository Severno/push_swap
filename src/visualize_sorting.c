/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:21:19 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 15:50:15 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		set_value(t_stack *stack, int search_value, int *i)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == search_value)
		{
			tmp->weight = *i;
			return ;
		}
		tmp = tmp->next;
	}
}

void			set_weight_to_each_value(t_stacks *stacks)
{
	t_stack	*tmp;
	int		arr[stacks->len_a + 1];
	int		i;

	tmp = stacks->visual_stack;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	tmp = stacks->visual_stack;
	i = 0;
	ft_quick_sort(arr, 0, stacks->len_a - 1);
	while (i < stacks->len_a)
	{
		set_value(tmp, arr[i], &i);
		i++;
	}
}

void			run_visualization(t_stacks *stacks)
{
	set_weight_to_each_value(stacks);
	visual_commands(stacks);
}
