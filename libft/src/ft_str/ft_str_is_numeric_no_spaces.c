/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric_no_spaces.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:51:54 by sapril            #+#    #+#             */
/*   Updated: 2019/12/09 13:51:54 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric_no_spaces(char *str)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9')
			|| (*str == '-' && *(str + 1) >= '0' && *(str + 1) <= '9'))
			str++;
		else
			return (0);
	}
	return (1);
}