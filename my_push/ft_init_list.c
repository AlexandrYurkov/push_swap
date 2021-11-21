#include "push_swap.h"

void	ft_init_list(t_list *list, void (*f)(int))
{
	while (list)
	{
		f(list->content);
		list = list->next;
	}
}
