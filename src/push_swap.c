/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:34 by sapril            #+#    #+#             */
/*   Updated: 2020/01/15 12:21:11 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * ЧТО ПРОИСХОДИТ В А
 * 1. Освобождаем пока не останется 3 или меньше элемента
 * 2. Сортируем их
 * 3. Назначаем верхний элемент "Топовым"
 * 4. Если в А осталось больше чем 3 элемента - продолжаем перекидывать в В
 * Что происходит в B
 * */

static int solver(t_stacks *stacks)
{
	int	sorted;
//	int	is_median;

	while (!(sorted = is_sorted(stacks->stack_a)) || stacks->stack_b != NULL)
	{
		//print_stacks(stacks->stack_a, stacks->stack_b);
		if (!sorted)
		{
			while (a_to_b(stacks))
				;
		} else
			stacks->stack_a_top = stacks->stack_a;
		//print_stacks(stacks->stack_a, stacks->stack_b);
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
//	printf("medium index value is %d\n", true_median(stacks, stacks->stack_a, ele));
	print_stacks(stacks->stack_a, stacks->stack_b);
//	sort_a(&stacks->stack_a, 3);
//	int arr[10] = {123, 32, 10 ,9, 8, 11, 0, 4, 5, 6}; // 0 4 5 6 8 9 10 11 32 123
//	int arr2[9] = {1,2,3,4,5,6,7,8,9};
//	int arr3[8] = {1,2,3,4,5,6,7,8};
//	int arr4[7] = {1,2,3,4,5,6,7};
//	int arr5[6] = {1,2,3,4,5,6};
//	int arr6[5] = {1,2,3,4,5};
//	int arr7[4] = {1,2,3,4};
//	int arr8[3] = {1,2,3};
//	ft_printf("%d\n", quick_select(arr, 0, sizeof(arr) / sizeof(arr[0]), 10 / 2 + 2)); // 6
//	ft_printf("%d\n", quick_select(arr2, 0, sizeof(arr2) / sizeof(arr2[0]), 9 / 2)); // 5
//	ft_printf("%f\n", 10.0 / 2.0);
//	ft_printf("%d\n", 10 / 2);
//	ft_printf("%f\n", 9.0 / 2.0);
//	ft_printf("%d\n", 9 / 2);
//	ft_printf("%d\n", quick_select(arr3, 0, sizeof(arr3) / sizeof(arr3[0]), 8 / 2));
//	ft_printf("%d\n", quick_select(arr4, 0, sizeof(arr4) / sizeof(arr4[0]), 7 / 2));
//	ft_printf("%d\n", quick_select(arr5, 0, sizeof(arr5) / sizeof(arr5[0]), 6 / 2));
//	ft_printf("%d\n", quick_select(arr6, 0, sizeof(arr6) / sizeof(arr6[0]), 5 / 2) + 2);
//	ft_printf("%d\n", quick_select(arr7, 0, sizeof(arr7) / sizeof(arr7[0]), 4 / 2));
//	ft_printf("%d\n", quick_select(arr8, 0, sizeof(arr8) / sizeof(arr8[0]), 3 / 2) + 2);
//	//print_stacks(stacks->stack_a, stacks->stack_b);
//	visualize_input_process(stacks);
//	set_stack_info(stacks);
//	ft_print_int_arr(stacks->unsorted_arr, 1, stacks->len_a);
//	ft_printf("\n");
//	ft_print_int_arr(stacks->sorted_arr, 1, stacks->len_a);

//	//print_stacks(stacks->stack_a, stacks->stack_b);
//	ft_printf(RED"Sum of operations: %d\n"RESET, stacks->sum_of_commands);
	free_data(stacks);
	return (0);
}