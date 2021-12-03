#include "push_swap.h"

void	ft_list_del_next(t_list **list)
{
	t_list	*tmp;

	tmp = (*list)->next->next;
	free((*list)->next);
	(*list)->next = tmp;
}
