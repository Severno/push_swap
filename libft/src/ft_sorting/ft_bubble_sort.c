#include "../../includes/libft.h"

static void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void ft_bubble_sort(int arr[], int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}