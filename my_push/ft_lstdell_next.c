#include "push_swap.h"

void	ft_list_del_next(t_stack **lst)
{
	t_stack	*new_next;

	new_next = (*lst)->next->next;
	free((*lst)->next);
	(*lst)->next = new_next;
}
