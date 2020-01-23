/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:31:54 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 18:19:23 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		add_val_to_arr(t_stacks *stacks,
		char *work_value, int arr_c, size_t num_limit)
{
	long long		temp_val;

	if (ft_str_is_numeric_no_spaces(work_value)
		&& ft_strlen(work_value) <= num_limit)
	{
		temp_val = ft_atol(work_value);
		if (temp_val > MAX_INTEGER || temp_val < MIN_INTEGER)
			exit(print_error(stacks));
		stacks->unsorted_arr[arr_c] = ft_atoi(work_value);
	}
	else
		exit(print_error(stacks));
}

void		check_bonus_flags(t_stacks *stacks,
		int *split_c, int *full_argv_size, int arg_c)
{
	if ((ft_strequ(stacks->split_argv[*split_c], "-v")
		|| ft_strequ(stacks->split_argv[*split_c], "-i"))
		&& *split_c == 0
		&& stacks->visual_please == 0
		&& arg_c == 2
		&& stacks->checker_run == -1)
	{
		ft_strequ(stacks->split_argv[*split_c], "-i")
		? stacks->input_process_please = 1 : 0;
		ft_strequ(stacks->split_argv[*split_c], "-v")
		? stacks->visual_please = 1 : 0;
		(*full_argv_size)--;
		(*split_c)++;
	}
}

void		check_value_condition(t_stacks *stacks,
		int *split_c, size_t *arr_c)
{
	size_t			num_limit;

	if (stacks->split_argv[*split_c])
	{
		num_limit = stacks->split_argv[*split_c][0] == '-'
					? NUM_LEN_WITH_SIGN : NUM_LEN_NO_SIGN;
		add_val_to_arr(stacks, stacks->split_argv[*split_c], *arr_c, num_limit);
		(*arr_c)++;
		(*split_c)++;
	}
}
