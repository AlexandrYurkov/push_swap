#include "push_swap.h"

void	ft_list_free(t_list **list)
{
	if (!list || !(*list))
		return ;
	ft_list_free(&((*list)->next));
	ft_list_delete(*list);
	*list = NULL;
}
