#include "push_swap.h"

void	ft_list_add_front(t_list **list, t_list *new)
{
	if (!list)
		return ;
	new->next = *list;
	*list = new;
}
