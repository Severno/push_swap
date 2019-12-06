#include "libft/includes/libft.h"
#include "includes/push_swap.h"

static void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int arr[] = {8};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_size);
	merge_sort(arr, 0, arr_size - 1);
	printArray(arr, sizeof(arr)/sizeof(arr[0]));

	return 0;
}