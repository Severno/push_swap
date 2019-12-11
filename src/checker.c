/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:13:05 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 08:11:07 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char *argv[])
{
	int		*num_arr;
	size_t	array_size;

	num_arr = NULL;
	array_size = 0;
	if (argc > 1)
	{
		num_arr = convert_str_to_int_array(argc, argv, &array_size);
		if (has_duplicates(num_arr, array_size))
			print_error(num_arr);
		else
			ft_merge_sort(num_arr, 0, array_size - 1);
	}
	ft_print_int_arr(num_arr, 1, array_size);
	free(num_arr);
	return (0);
}