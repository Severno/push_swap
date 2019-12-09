#include "includes/libft.h"

static void print_arr(int arr[], int length)
{
	int i;

	i = 0;
	while (i < length)
		ft_printf("%d ", arr[i++]);
}

int main()
{
	int length;
	int arr[] = {3213, 3, 12, 42,545454, 1, -123};

	length = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, length);
	ft_merge_sort(arr, 0, length - 1);
	ft_printf("\n");
	print_arr(arr, length);
	ft_printf("Hello world!");
}
