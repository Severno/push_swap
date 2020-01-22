/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:16:12 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 18:31:28 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		get_full_argument_size(int argc, char *argv[])
{
	char	**split_str;
	int		size;
	int		i;

	i = 1;
	size = 0;
	while (i < argc)
	{
		split_str = ft_strsplit(argv[i], ' ');
		size += ft_get_number_of_substrings(split_str);
//		free_split_str(&split_str);
		i++;
	}
	return (size);
}

void			free_split_str(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		if ((*tab)[i] != NULL)
			free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = 0;
}

void			convert_argv_to_int_array(int argc,
		char *argv[], int *array_size, t_stacks *stacks)
{
	size_t			arr_c;
	int				split_c;
	int				arg_c;
	int				full_argv_size;

	arr_c = 0;
	split_c = 0;
	arg_c = 1;
	full_argv_size = get_full_argument_size(argc, argv);
	stacks->unsorted_arr = (int *)ft_memalloc(sizeof(int) * full_argv_size);
	while ((int)arr_c < full_argv_size)
	{
		stacks->split_argv = ft_strsplit(argv[arg_c++], ' ');
		while (stacks->split_argv[split_c])
		{
			check_bonus_flags(stacks, &split_c, &full_argv_size, arg_c);
			check_value_condition(stacks, &split_c, &arr_c);
		}
		split_c = 0;
//		free_split_str(&stacks->split_argv);
	}
	*array_size = arr_c;
}

int				has_duplicates(int *num_arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
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
