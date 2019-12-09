/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:16:12 by sapril            #+#    #+#             */
/*   Updated: 2019/12/09 16:18:17 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_input_condition(int argc, char *argv[])
{
	int arg_count;

	arg_count = 1;
	if (argc == 2 && ft_str_is_numeric_with_spaces(argv[arg_count]))
		return (ONE_INPUT_PARAM);
	else if (argc > 2)
		return (MULTIPLE_INPUT_PARAMS);
	else
		return (ERROR);
}

int		*convert_str_to_int_array(int argc, char *argv[], size_t *array_size)
{
	char input_condition;

	input_condition = (char)check_input_condition(argc, argv);
	if (input_condition == MULTIPLE_INPUT_PARAMS)
		return (handle_multiple_input_params(argc, argv, array_size));
	else if (input_condition == ONE_INPUT_PARAM)
		return (handle_one_input_params(argv, array_size));
	else
		print_error();
	return (NULL);
}

int has_duplicates(int *num_arr, size_t size)
{
	size_t i;
	size_t j;

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