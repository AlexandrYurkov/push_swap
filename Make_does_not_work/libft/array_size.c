#include "libft.h"

int	array_size(char	**array)
{
	int	i;

	i = 0;
	while (array + i && array[i])
		i++;
	return (i);
}