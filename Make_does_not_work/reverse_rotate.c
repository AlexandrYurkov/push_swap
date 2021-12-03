#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_list_add_front(stack, tmp->next);
	tmp->next = NULL;
}

int	rra(t_list **a, t_list **b)
{
	(void)b;
	reverse_rotate(a);
	return (RRA);
}

int	rrb(t_list **a, t_list **b)
{
	(void)a;
	reverse_rotate(b);
	return (RRB);
}

int	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return (RRR);
}