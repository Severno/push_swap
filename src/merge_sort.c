/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:16:42 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 18:33:06 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
static void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

static void merge(int arr[], int low, int middle, int high)
{
	int left_i;
	int right_i;
	int arr_i;
	int left_arr[middle - low + 1];
	int right_arr[high - middle];

	left_i = 0;
	right_i = 0;
	arr_i = low;

	while (left_i < middle - low + 1)
	{
		left_arr[left_i] = arr[low + left_i];
		left_i++;
	}
	while (right_i < high - middle)
	{
		right_arr[right_i] = arr[middle + right_i + 1];
		right_i++;
	}
	right_i = 0;
	left_i = 0;
	while (left_i < middle - low + 1 && right_i < high - middle)
	{
		if (left_arr[left_i] < right_arr[right_i])
			arr[arr_i] = left_arr[left_i++];
		else
			arr[arr_i] = right_arr[right_i++];
		arr_i++;
	}

	while (left_i < middle - low + 1)
		arr[arr_i++] = left_arr[left_i++];

	while (right_i < high - middle)
		arr[arr_i++] = right_arr[right_i++];
}

void merge_sort(int arr[], int low, int high)
{
	int middle;

	middle = low+(high-low)/2;
	if (low < high)
	{
		merge_sort(arr, low, middle);
		merge_sort(arr, middle + 1, high);
		merge(arr, low, middle, high);
	}
}
