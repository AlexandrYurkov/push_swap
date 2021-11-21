#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	ft_list_add_front(b, tmp);
}

int	pa(t_list **a, t_list **b)
{
	push(b, a);
	return (PA);
}

int	pb(t_list **a, t_list **b)
{
	push(a, b);
	return (PB);
}