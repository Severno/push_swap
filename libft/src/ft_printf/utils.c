/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:17:18 by sapril            #+#    #+#             */
/*   Updated: 2019/11/23 17:12:43 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	p_sign(char sign, int *bits)
{
	ft_putchar(sign);
	(*bits)++;
}

int		ft_max_of_two(int a, int b)
{
	return ((a > b) ? a : b);
}

int		ft_min_of_two(int a, int b)
{
	return ((a < b) ? a : b);
}

int		ft_max_of_three(int a, int b, int c)
{
	if (a >= b && a > c)
		return (a);
	else if (b >= a && b > c)
		return (b);
	else if (c >= a && c > b)
		return (c);
	return (0);
}

int		ft_middle_of_three(int a, int b, int c)
{
	if (a > b && a < c)
		return (a);
	else if (b > a && b < c)
		return (b);
	else if (c > a && c < b)
		return (c);
	return (0);
}
