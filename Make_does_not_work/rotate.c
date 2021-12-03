#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_list_add_back(stack, tmp);
}

int	ra(t_list **a, t_list **b)
{
	(void)b;
	rotate(a);
	return (RA);
}

int	rb(t_list **a, t_list **b)
{
	(void)a;
	rotate(b);
	return (RB);
}

int	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	return (RR);
}