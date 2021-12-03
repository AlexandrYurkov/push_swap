#include "push_swap.h"

void	ft_list_add_front(t_list **list, t_list *news)
{
	if (!list)
		return ;
	news->next = *list;
	*list = news;
}
