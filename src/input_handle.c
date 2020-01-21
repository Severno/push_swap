/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:16:12 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 12:16:57 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_input_condition(int arg_c, char *arg_v[])
{
	int arg_count;

	arg_count = 1;
	if (arg_c == 2 && ft_str_is_numeric_with_spaces(arg_v[arg_count]))
		return (ONE_INPUT_PARAM);
	else if (arg_c > 2)
		return (MULTIPLE_INPUT_PARAMS);
	else
		return (ERROR);
}

int		*convert_str_to_int_array(int arg_c, char *arg_v[], int *array_size)
{
	int input_condition;

	input_condition = check_input_condition(arg_c, arg_v);
	if (input_condition == MULTIPLE_INPUT_PARAMS)
		return (handle_multiple_input_params(arg_c, arg_v, array_size));
	else if (input_condition == ONE_INPUT_PARAM)
		return (handle_one_input_params(arg_v, array_size));
	else
		exit(print_error());
}

int has_duplicates(int *num_arr, int size)
{
	int i;
	int j;

	i = 0;
	while(i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (num_arr[i] == num_arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
