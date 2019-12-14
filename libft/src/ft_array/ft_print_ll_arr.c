#include "../../includes/libft.h"

void		ft_print_ll_arr(long long *ll_arr, int in_line, size_t size)
{
	size_t i;

	i = 0;
	if (in_line == 1)
		while (i < size)
			ft_printf("%lld ", ll_arr[i++]);
	else if (in_line == 0)
		while (i < size)
			ft_printf("%lld\n", ll_arr[i++]);
}