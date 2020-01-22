/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_print_loops.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:02:03 by sapril            #+#    #+#             */
/*   Updated: 2020/01/22 15:49:19 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	five_loop(int *i)
{
	int fives;

	fives = *i / 5;
	while (--fives >= 0)
	{
		write(1, "_____", 5);
		*i -= 5;
	}
}

void	ten_loop(int *i)
{
	int decades;

	decades = *i / 10;
	while (--(decades) >= 0)
	{
		write(1, "__________", 10);
		*i -= 10;
	}
}

void	hundred_loop(int *i)
{
	int hundreds;

	hundreds = *i / 100;
	while (--hundreds >= 0)
	{
		write(1, "_________________________________________"
		"___________________________________________________________", 100);
		*i -= 100;
	}
}
