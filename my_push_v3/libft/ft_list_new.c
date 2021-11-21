#include "libft.h"

t_list	*ft_list_new(int content)
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
