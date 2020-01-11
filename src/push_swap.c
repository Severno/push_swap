/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:34 by sapril            #+#    #+#             */
/*   Updated: 2020/01/11 19:25:44 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// check_arguments_type(t_stacks *stacks)

//static void		check_and_init_stacks(t_stacks **stacks, int argc, char *argv[])
//{
//
//	int		*unsorted_arr;
//	int		array_size;
//
//	array_size = 0;
//	if (argc > 1)
//	{
//		unsorted_arr = convert_str_to_int_array(argc, argv, &array_size);
//		if (has_duplicates(unsorted_arr, array_size))
//		{
//			free(unsorted_arr);
//			print_error();
//		}
//		stacks_init(stacks, unsorted_arr, array_size);
//	}
//	else
//		exit(1);
//}

static int solver(t_stacks *stacks)
{
	int	sorted;
//	int	is_median;

	while (!(sorted = is_sorted(stacks->stack_a)) || stacks->stack_b != NULL)
	{
		print_stacks(stacks->stack_a, stacks->stack_b);
		if (!sorted)
		{
			while (a_to_b(stacks))
				;
		} else
			stacks->stack_a_top = stacks->stack_a;
		print_stacks(stacks->stack_a, stacks->stack_b);
		b_to_a(stacks);
	}
	return (1);
}

int			main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	stacks = create_stacks(argc, argv);
	if (stacks->stack_a == NULL || is_sorted(stacks->stack_a) == 1
	|| has_duplicates(stacks->unsorted_arr, stacks->len_a))
		exit(free_data(stacks));
	solver(stacks);
	printf("medium index value is %d\n", true_median(stacks, stacks->stack_a));
//	print_stacks(stacks->stack_a, stacks->stack_b);
//	sort_a(&stacks->stack_a, 3);
	print_stacks(stacks->stack_a, stacks->stack_b);
	visualize_input_process(stacks);
//	set_stack_info(stacks);
//	ft_print_int_arr(stacks->unsorted_arr, 1, stacks->len_a);
//	ft_printf("\n");
//	ft_print_int_arr(stacks->sorted_arr, 1, stacks->len_a);

//	print_stacks(stacks->stack_a, stacks->stack_b);
//	ft_printf(RED"Sum of operations: %d\n"RESET, stacks->sum_of_commands);
	free_data(stacks);
	return (0);
}