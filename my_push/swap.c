#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*next_elem;

	if (!*stack || !(*stack)->next)
		return ;
	next_elem = (*stack)->next;
	(*stack)->next = next_elem->next;
	next_elem->next = *stack;
	(*stack) = next_elem;
}

int	sa(t_list **a, t_list **b)
{
	(void)b;
	swap(a);
	return (SA);
}

int	sb(t_list **a, t_list **b)
{
	(void)a;
	swap(b);
	return (SB);
}

int	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	return (SS);
}
