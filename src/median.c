#include "../includes/push_swap.h"


int get_elems_num(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;

}

void swap(int *arr, int i, int j) {
	int tmp;

	if (i != j)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

int partition(int *arr, int left, int right)
{
	int pivot;
	int i;
	int j;

	j = left - 1;
	i = left;
	pivot = arr[right];
	while (j < right)
	{
		if (arr[j] <= pivot) {
			i++;
			swap(arr, i, j);
		}
		j++;
	}
	return i;
}

int qs(int arr, int left, int right)
{
	int p
	if (left < right)
	{

	}

}

int true_median_a(t_stacks *stacks) {
	t_stack	*tmp_stack;
	int		arr[stacks->ac + 1];
	int		i;
	int		j;

	tmp_stack = stacks->stack_a;
	i = 0;
	j = 0;
	while (tmp_stack)
	{
		arr[i++] = tmp_stack->value;
		tmp_stack = tmp_stack->next;
	}
	i = 0;

}