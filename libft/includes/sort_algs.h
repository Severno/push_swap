/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:47:41 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 18:47:41 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGS_H
#define SORT_ALGS_H

typedef struct	s_merge_sort
{
	int low;
	int middle;
	int high;
	int left_arr_size;
	int right_arr_size;
	int *left_arr;
	int *right_arr;
}				t_merge_sort;

void			ft_merge_sort(int arr[], int low, int high);

#endif
