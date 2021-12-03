#include "libft.h"

void	ft_swap(int *a, int *b) // переименовать в swap_point
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
