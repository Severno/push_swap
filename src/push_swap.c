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
		if (!sorted)
		{
			while (a_to_b(stacks))
				;
		} else
			stacks->stack_a_top = stacks->stack_a;
		////print_stacks(stacks->stack_a, stacks->stack_b);
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
	printf("argv = %s\n", argv[1]);
	if (stacks->stack_a == NULL || is_sorted(stacks->stack_a) == 1
	|| has_duplicates(stacks->unsorted_arr, stacks->len_a))
		exit(free_data(stacks));
//	for (int i = 500; i >= 0; --i) {
//		printf("%d ", i);
//	}
//	int length;
//	int arr[] = {0, 0, 4, 2, 5, 1};
//
//	length = sizeof(arr) / sizeof(arr[0]);
//	ft_print_int_arr(arr, 1, length);
//	ft_merge_sort(arr, 0, length - 1);
//	ft_printf("\n");
//	ft_print_int_arr(arr, 1, length);
	solver(stacks);

	print_stacks(stacks->stack_a, stacks->stack_b);
	printf(RED"Operations %d\n"RESET, stacks->operations);
//	visualize_input_process(stacks);
//	if (is_sorted(stacks->stack_a))
	free_data(stacks);
	return (0);
}