#include "push_swap.h"

void	ft_swap_list(t_list **stack)
{
	t_list	*next_elem;

	if (!*stack || !(*stack)->next)
		return ;
	next_elem = (*stack)->next;
	(*stack)->next = next_elem->next;
	next_elem->next = *stack;
	(*stack) = next_elem;
}

int	sa(t_list **st_a, t_list **st_b)
{
	(void)st_b;
	ft_swap_list(st_a);
	return (SA);
}

int	sb(t_list **st_a, t_list **st_b)
{
	(void)st_a;
	ft_swap_list(st_b);
	return (SB);
}

int	ss(t_list **st_a, t_list **st_b)
{
	ft_swap_list(st_a);
	ft_swap_list(st_b);
	return (SS);
}