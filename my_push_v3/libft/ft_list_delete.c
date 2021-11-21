#include "libft.h"

void	ft_list_delete(t_list *list)
{
	free(list);
	list = NULL;
}
