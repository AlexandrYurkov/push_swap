#include "push_swap.h"

static void	find_place(t_list **a, t_list **b, t_check *info, t_list **comms)
{
	(*b)->sort = -1;
	pa(a, b);
	ft_list_add_back(comms, ft_list_new(PA));
	ra(a, b);
	ft_list_add_back(comms, ft_list_new(RA));
	info->next_elem++;
}

static void	swap_if_next(t_list **a, t_list **b, t_check *info, t_list **comms)
{
	while ((*a && (*a)->next && (*a)->next->order == info->next_elem)
		|| (*b && (*b)->next && (*b)->next->order == info->next_elem))
	{
		if (*a && (*a)->next && (*a)->next->order == info->next_elem)
		{
			sa(a, b);
			ft_list_add_back(comms, ft_list_new(SA));
		}
		else if ((*b)->order == info->next_elem + 1)
		{
			pa(a, b);
			ft_list_add_back(comms, ft_list_new(PA));
		}
		else if ((*b)->order < info->mid)
		{
			sb(a, b);
			ft_list_add_back(comms, ft_list_new(SB));
		}
		else if ((*b)->order >= info->mid)
			break ;
	}
}

static void	check_bottom_value(t_list **b, t_check *info, t_list **comms)
{
	t_list	*last;

	last = ft_list_last(*b);
	if (last && last->order == info->next_elem)
	{
		rrb(NULL, b);
		ft_list_add_back(comms, ft_list_new(RRB));
	}
}

void	check_top_value(t_list **a, t_list **b, t_check *info, t_list **comms)
{
	swap_if_next(a, b, info, comms);
	check_bottom_value(b, info, comms);
	while ((*a && (*a)->order == info->next_elem)
		|| (*b && (*b)->order == info->next_elem))
	{
		if (*b && (*b)->order == info->next_elem)
			find_place(a, b, info, comms);
		else
		{
			(*a)->sort = -1;
			ra(a, b);
			ft_list_add_back(comms, ft_list_new(RA));
			info->next_elem++;
		}
		swap_if_next(a, b, info, comms);
		check_bottom_value(b, info, comms);
	}
}