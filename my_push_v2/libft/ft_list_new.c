#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->value = content;
	list->next = NULL;
	list->sort = 0;
	list->order = 0;
	return (list);
}
