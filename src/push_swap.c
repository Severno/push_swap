/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:34 by sapril            #+#    #+#             */
/*   Updated: 2019/12/11 15:50:38 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// check_arguments_type(t_stacks *stacks)

static void check_and_init_stacks(t_stacks **stacks, int argc, char *argv[])
{
	int			*unsorted_arr;
	size_t		array_size;

	array_size = 0;
	if (argc > 1)
	{
		unsorted_arr = convert_str_to_int_array(argc, argv, &array_size);
		if (has_duplicates(unsorted_arr, array_size))
		{
			free(unsorted_arr);
			print_error();
		}
		stacks_init(stacks, unsorted_arr, array_size);
	}
	else
		exit(1);
}

int main(int argc, char *argv[])
{
	t_stacks	*stacks;

	stacks = NULL;
	check_and_init_stacks(&stacks, argc, argv);
	if (stacks->a_head == NULL || is_sorted(stacks->a_head) == 1)
		return (0);
	if (argc >= 5 && argc <= 50)
		ps_small_range(stacks);
//	else if (argc >= 8 && argc <= 800)
//		ps_middle_range(stacks);
//	else if (argc >= 801)
//		ps_big_range(stacks);
//	else
//		;
//	visualize_input_process(stacks);
	print_stacks(stacks->a_head, stacks->b_head);
	free_stacks(stacks);
	return (0);
}