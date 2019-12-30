/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:34 by sapril            #+#    #+#             */
/*   Updated: 2019/12/18 09:49:16 by sapril           ###   ########.fr       */
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

//static set_stack_info(t_stacks *stacks)
//{
//
//}

void partition(int arr[], int left, int right)
{
	if (left == right)
		return;
	printf("Left = %d, Right = %d. Arr with borders = \n", left, right);
	for (int i = left; i < right; ++i) {
		putchar(arr[left]);
	}
}

void qs(int arr[], int left, int right)
{
	printf("Left = %d, Right = %d. Arr with borders = \n", left, right);
	for (int i = left; i <= right; i++) {
		printf("%d ", (arr[i]));
	}
	printf("\n");
	if (left < right)
	{

		int middle = left+(right-left)/2;
		qs(arr, left, middle);
		qs(arr, middle+1, right);
	}
}

int				main(int argc, char *argv[])
{
//	t_stacks	*stacks;

//	if (argc < 2)
//		exit(1);
//	stacks = create_stacks(argc, argv);
	int arr[] = {1,23,6,7,10,2,3,18};
	qs(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
//	if (stacks->stack_a == NULL || is_sorted(stacks->stack_a) == 1
//	|| has_duplicates(stacks->unsorted_arr, stacks->len_a))
//		exit(free_data(stacks));
//	visualize_input_process(stacks);
//	set_stack_info(stacks);
//	ft_print_int_arr(stacks->unsorted_arr, 1, stacks->len_a);
//	ft_printf("\n");
//	ft_print_int_arr(stacks->sorted_arr, 1, stacks->len_a);

//	print_stacks(stacks->stack_a, stacks->stack_b);
//	ft_printf(RED"Sum of operations: %d\n"RESET, stacks->sum_of_commands);
//	free_data(stacks);
	return (0);
}