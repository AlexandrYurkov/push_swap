#include "push_swap.h"

int	ft_check_number(char *argv, t_list *a, int *i)
{
	if (argv[0] == '-' || argv[0] == '+')
	{
		if (argv[1] != 0)
			(*i)++;
		else
			return (0);
	}
	while (argv[*i])
	{
		if (!ft_isdigit(argv[*i]))
			return (0);
		(*i)++;
	}
	*i = ft_atoi(argv);
	if ((*i == 0 && argv[1] != '\0') || (*i == -1 && argv[2] != '\0'))
		return (0);
	while (a)//проверка на дубликаты
	{
		if (*i == a->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_values(t_list *s, int value)
{
	while (s)
	{
		if (s->order >= value)
			return (1);
		s = s->next;
	}
	return (0);
}

int	check_sort(t_list *st_a)
{
	while (st_a->next)
	{
		if (st_a->value > st_a->next->value)
			return (0);
		st_a = st_a->next;
	}
	return (1);
}

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