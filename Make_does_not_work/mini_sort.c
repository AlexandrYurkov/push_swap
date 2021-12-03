#include "push_swap.h"

int	search_next_elem(t_list *stack)
{
	int	next_elem;

	next_elem = 6;
	while (stack)
	{
		if (stack->order < next_elem)
			next_elem = stack->order;
		stack = stack->next;
	}
	return (next_elem);
}

void	sort_three_st_a(t_list **st_a, t_list **instr)
{
	int	next_elem;

	next_elem = search_next_elem(*st_a);
	if (check_sort(*st_a))
		return ;
	if ((*st_a)->next->order == next_elem && (*st_a)->order < ft_list_last(*st_a)->order)
		ft_list_add_back(instr, ft_list_new(sa(st_a, NULL)));
	else if ((*st_a)->next->order == next_elem && (*st_a)->order > ft_list_last(*st_a)->order)
		ft_list_add_back(instr, ft_list_new(ra(st_a, NULL)));
	else if ((*st_a)->order == next_elem)
	{
		ft_list_add_back(instr, ft_list_new(rra(st_a, NULL)));
		ft_list_add_back(instr, ft_list_new(sa(st_a, NULL)));
	}
	else if ((*st_a)->order < (*st_a)->next->order)
		ft_list_add_back(instr, ft_list_new(rra(st_a, NULL)));
	else
	{
		ft_list_add_back(instr, ft_list_new(sa(st_a, NULL)));
		ft_list_add_back(instr, ft_list_new(rra(st_a, NULL)));
	}
}

void	sort_three_st_b(t_list **st_b, t_list **instr)
{
	int	next_elem;

	next_elem = search_next_elem(*st_b);
	if (check_sort(*st_b))
		return ;
	if ((*st_b)->next->order == next_elem && (*st_b)->order < ft_list_last(*st_b)->order)
		ft_list_add_back(instr, ft_list_new(sb(NULL, st_b)));
	else if ((*st_b)->next->order == next_elem && (*st_b)->order > ft_list_last(*st_b)->order)
		ft_list_add_back(instr, ft_list_new(rb(NULL, st_b)));
	else if ((*st_b)->order == next_elem)
	{
		ft_list_add_back(instr, ft_list_new(rrb(NULL, st_b)));
		ft_list_add_back(instr, ft_list_new(sb(NULL, st_b)));
	}
	else if ((*st_b)->order < (*st_b)->next->order)
		ft_list_add_back(instr, ft_list_new(rrb(NULL, st_b)));
	else
	{
		ft_list_add_back(instr, ft_list_new(sb(NULL, st_b)));
		ft_list_add_back(instr, ft_list_new(rrb(NULL, st_b)));
	}
}

void	redirect_stack(t_list **st_a, t_list **st_b, t_list **comms)
{
	int	next_elem;

	next_elem = 1;
	while (*st_b || !check_sort(*st_a))
	{
		if ((*st_a)->order == next_elem)
			ft_list_add_back(comms, ft_list_new(ra(st_a, st_b)));
		else if ((*st_b)->order == next_elem)
		{
			ft_list_add_back(comms, ft_list_new(pa(st_a, st_b)));
			ft_list_add_back(comms, ft_list_new(ra(st_a, st_b)));
		}
		next_elem++;
	}
}

void	mini_sort(t_list **st_a, int size)
{
	t_list		*instr;
	t_list		*st_b;

	instr = NULL;
	st_b = NULL;
	if (check_sort(*st_a))
		return ;
	if (size == 2)
		ft_list_add_back(&instr, ft_list_new(sa(st_a, &st_b)));
	if (size > 2)
	{
		while (ft_list_size(*st_a) != 3)
			ft_list_add_back(&instr, ft_list_new(pb(st_a, &st_b)));
		sort_three_st_a(st_a, &instr);
		if (ft_list_size(st_b) > 1)
			sort_three_st_b(&st_b, &instr);
		redirect_stack(st_a, &st_b, &instr);
	}
	change(&instr);
	ft_print_instr(instr);
	ft_all_free(st_a, &st_b, &instr);
}