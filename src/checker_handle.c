/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:30:18 by sapril            #+#    #+#             */
/*   Updated: 2019/12/09 16:18:17 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			*handle_multiple_input_params(int argc, char *argv[], size_t *array_size)
{
	size_t	arg_count;
	size_t	i;
	int		*num_arr;

	arg_count = 1;
	i = 0;
	num_arr = (int *)ft_memalloc(sizeof(int) * (argc - 1));
	while (argv[arg_count])
	{
		if (ft_str_is_numeric_no_spaces(argv[arg_count]))
			num_arr[i++] = ft_atoi(argv[arg_count++]);
		else
		{
			free(num_arr);
			print_error();
		}
	}
	*array_size = i;
	return (num_arr);
}

int			*handle_one_input_params(char *argv[], size_t *array_size)
{
	char	**split_str;
	size_t	arg_count;
	size_t	i;
	int		*num_arr;

	arg_count = 1;
	i = 0;
	split_str = ft_strsplit(argv[arg_count], ' ');
	num_arr = (int *)ft_memalloc(sizeof(int) * ft_get_number_of_substrings(split_str));
	while(split_str[i]){
		if (ft_str_is_numeric_no_spaces(split_str[i]))
			num_arr[i] = ft_atoi(split_str[i]);
		else
		{
			free(num_arr);
			print_error();
		}
		i++;
	}
	*array_size = i;
	return (num_arr);
}

void		free_push_swap(int *arr_num)
{
	free(arr_num);
}

void		print_error()
{
	ft_putstr("Error\n");
	exit(1);
}
