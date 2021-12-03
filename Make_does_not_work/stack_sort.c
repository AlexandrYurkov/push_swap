#include "push_swap.h"

void	ft_search_mid(t_check *info, int max)
{
	info->max = max;
	info->mid = (info->max - info->next_elem) / 2 + info->next_elem;
}

void	sort_st_b(t_list **st_a, t_list **st_b, t_check *info, t_list **instr)
{
	int	i;
	int	size;

	i = 0;
	size = info->mid - info->next_elem + 1;
	while (i < size)
	{
		if ((*st_a)->order <= info->mid)
		{
			ft_list_add_back(instr, ft_list_new(pb(st_a, st_b)));
			i++;
		}
		else
			ft_list_add_back(instr, ft_list_new(ra(st_a, st_b)));
	}
}

void	sort_st_a(t_list **st_a, t_list **st_b, t_check *info, t_list **instr)
{
	while (*st_b && check_values(*st_b, info->mid))
	{
		check_top_value(st_a, st_b, info, instr);
		if (!*st_b)
			return ;
		if ((*st_b)->order < info->mid)
			ft_list_add_back(instr, ft_list_new(rb(st_a, st_b)));
		else
		{
			(*st_b)->sort = info->check_sort;
			ft_list_add_back(instr, ft_list_new(pa(st_a, st_b)));
		}
	}
	check_top_value(st_a, st_b, info, instr);
}

void	finish_sort(t_list **st_a, t_list **st_b, t_check *info, t_list **instr)
{	
	int	tmp;

	tmp = (*st_a)->sort;
	while (tmp > 0)
	{
		while ((*st_a)->sort == tmp)
		{
			if ((*st_a)->order > info->max)
				info->max = (*st_a)->order;
			ft_list_add_back(instr, ft_list_new(pb(st_a, st_b)));
			check_top_value(st_a, st_b, info, instr);
		}
		ft_search_mid(info, info->max);
		while (*st_b != NULL)
		{
			info->check_sort++;
			sort_st_a(st_a, st_b, info, instr);
			ft_search_mid(info, info->mid);
		}
		tmp = (*st_a)->sort;
	}
}

void	stack_sort(t_list **st_a, int size)
{
	t_list		*st_b;
	t_check		*info;
	t_list		*instr;

	st_b = NULL;
	instr = NULL;
	info = ft_new_info(size);
	while (st_b || !check_sort(*st_a))
	{
		sort_st_b(st_a, &st_b, info, &instr);
		while (info->check_sort && ft_list_last(*st_a)->sort != -1)
			ft_list_add_back(&instr, ft_list_new(rra(st_a, &st_b)));
		while (st_b != NULL)
		{
			ft_search_mid(info, info->mid);
			info->check_sort++;
			sort_st_a(st_a, &st_b, info, &instr);
		}
		finish_sort(st_a, &st_b, info, &instr);
		ft_search_mid(info, size);
	}
	change(&instr);
	ft_print_instr(instr);
	free(info);
	ft_all_free(st_a, &st_b, &instr);
}