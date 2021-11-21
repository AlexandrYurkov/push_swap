#include "push_swap.h"

void	ft_list_add_back(t_list **list, t_list *new)
{
	if (!list)
		return ;
	if (*list)
		ft_list_last(*list)->next = new;
	else
		*list = new;
}
