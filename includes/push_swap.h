/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:42:56 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 19:10:10 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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

void			merge_sort(int arr[], int low, int high);

#endif
