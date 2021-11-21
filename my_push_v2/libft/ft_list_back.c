#include "push_swap.h"

void	ft_list_back(t_list *list, void (*f)(int))
{
	while (list)
	{
		f(list->value);
		list = list->next;
	}
}
