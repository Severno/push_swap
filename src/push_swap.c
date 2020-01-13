/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:00:34 by sapril            #+#    #+#             */
/*   Updated: 2020/01/13 20:14:33 by sapril           ###   ########.fr       */
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