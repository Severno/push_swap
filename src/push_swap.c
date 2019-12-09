/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:34 by sapril            #+#    #+#             */
/*   Updated: 2019/12/09 18:10:42 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_el *create_new_stack_elem(t_ps_params *ps_params, int value)
{
	t_el		*new_elem;
	(void)ps_params;

	if (!(new_elem = (t_el*)ft_memalloc(sizeof(t_el))))
		return (NULL);
	new_elem->value = value;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

void push_array_to_stack(t_stack *stack_a, t_ps_params *ps_params)
{
	t_el		*begin_list;
	t_el		*start_list_tmp;
	t_el		*end_list_tmp;
	size_t		i;

	i = 1;
	begin_list = create_new_stack_elem(ps_params, ps_params->sorted_arr[0]);
	start_list_tmp = begin_list;
	while (i < ps_params->length - 1)
	{
		if (i == 1)
		{
			start_list_tmp->next = create_new_stack_elem(ps_params, ps_params->sorted_arr[i]);
			start_list_tmp->prev = create_new_stack_elem(ps_params, ps_params->sorted_arr[ps_params->length - 1]);
		}
		else if (i == ps_params->length - 1)
		{
			start_list_tmp->next = create_new_stack_elem(ps_params, ps_params->sorted_arr[0]);
			start_list_tmp->prev = create_new_stack_elem(ps_params, ps_params->sorted_arr[i - 1]);
		}
		else
		{
			start_list_tmp->next = create_new_stack_elem(ps_params, ps_params->sorted_arr[i]);
			start_list_tmp->prev = create_new_stack_elem(ps_params, ps_params->sorted_arr[i - 1]);
		}
		start_list_tmp = begin_list->next;
		i++;
	}
	end_list_tmp = start_list_tmp;
	stack_a->begin_list = begin_list;
}

static void print_stack_elems(t_stack *stack_a, t_ps_params *ps_params)
{
	size_t i;
	t_el *tmp_elem;

	i = 0;
	tmp_elem = stack_a->begin_list;
	while(i < ps_params->length - 1)
	{
		ft_printf("%d\n", tmp_elem->value);
		tmp_elem = tmp_elem->next;
	}
}

int main(int argc, char *argv[])
{
	t_stack		*stack_a;
//	t_stack		*stack_b;
	t_ps_params	*ps_param;
	int		*num_arr;
	size_t	array_size;

	num_arr = NULL;
	array_size = 0;

	ps_param = (t_ps_params *)ft_memalloc(sizeof(t_ps_params));
	if (argc > 1)
	{
		num_arr = convert_str_to_int_array(argc, argv, &array_size);
		if (has_duplicates(num_arr, array_size))
			print_error(num_arr);
		else
			ft_merge_sort(num_arr, 0, array_size - 1);
	}
	ps_param->length = array_size;
	ps_param->sorted_arr = num_arr;
	stack_a = (t_stack *)ft_memalloc(sizeof(t_el) * array_size);
	push_array_to_stack(stack_a, ps_param);
	ft_print_int_arr(num_arr, 1, array_size);
	print_stack_elems(stack_a, ps_param);
	free(num_arr);
	return (0);
}