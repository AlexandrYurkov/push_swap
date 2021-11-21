#include "push_swap.h"

void	push(t_stack **out, t_stack **in)
{
	t_stack	*elem;

	if (!*out)
		return ;
	elem = *out;
	*out = (*out)->next;
	ft_lstadd_front(in, elem);
}

int	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	return (PA);
}

int	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	return (PB);
}

//---------------------------------
void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	ft_lstadd_front(stack, temp->next);
	temp->next = NULL;
}

int	rra(t_stack **a, t_stack **b)
{
	(void)b;
	reverse_rotate(a);
	return (RRA);
}

int	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	reverse_rotate(b);
	return (RRB);
}

int	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return (RRR);
}
//-------------------------------------------------------
void	rotate(t_stack **stack)
{
	t_stack	*first;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_list_add_back(stack, first);
}

int	ra(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
	return (RA);
}

int	rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
	return (RB);
}

int	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	return (RR);
}
//-----------------------------------------------------------
void	swap(t_stack **stack)
{
	t_stack	*next_elem;

	if (!*stack || !(*stack)->next)
		return ;
	next_elem = (*stack)->next;
	(*stack)->next = next_elem->next;
	next_elem->next = *stack;
	(*stack) = next_elem;
}

int	sa(t_stack **a, t_stack **b)
{
	(void)b;
	swap(a);
	return (SA);
}

int	sb(t_stack **a, t_stack **b)
{
	(void)a;
	swap(b);
	return (SB);
}

int	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	return (SS);
}
//-------------------------------------------------------------
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
			ft_list_add_back(instr, ft_list_new(rb(a, b)));
		else
		{
			(*st_b)->sort = info->check_sort;
			ft_list_add_back(instr, ft_list_new(pa(a, b)));
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
		fill_info(info, info->max);
		while (*st_b != NULL)
		.
		{
			info->check_sort++;
			move_to_a(st_a, st_b, info, instr);
			fill_info(info, info->mid);
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
	info = ft_new_info(size);//
	while (st_b || !check_sort(*st_a))
	{
		sort_st_b(st_a, &st_b, info, &instr);
		while (info->check_sort && ft_list_last((*st_a)->sort) != -1)
			ft_list_add_back(&instr, ft_list_new(rra(st_a, &st_b)));
		while (st_b != NULL)
		{
			ft_search_mid(info, info->mid);
			info->check_sort++;
			sort_st_a(st_a, &st_b, info, &instr);
		}
		move_to_b_flag(st_a, &st_b, info, &instr);
		ft_search_mid(info, size);
	}
	replace(&instr);
	output(instr);
	free(info);
	clear_all(a, &st_b, &instr);
}
//----------------------------------------------------

//------------------------------------------------------------------------
void	find_place(t_stack **a, t_stack **st_b, t_info *info, t_stack **comms)
{
	(*b)->flag = -1;
	pa(a, b);
	ft_list_add_back(comms, ft_list_new(PA));
	ra(a, b);
	ft_list_add_back(comms, ft_list_new(RA));
	info->next++;
}

void	swap_if_next(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	while ((*a && (*a)->next && (*a)->next->order == info->next)
		|| (*b && (*b)->next && (*b)->next->order == info->next))
	{
		if (*a && (*a)->next && (*a)->next->order == info->next)
		{
			sa(a, b);
			ft_list_add_back(comms, ft_list_new(SA));
		}
		else if ((*b)->order == info->next + 1)
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

void	check_bottom_value(t_stack **b, t_info *info, t_stack **comms)
{
	t_stack	*last;

	last = ft_list_last(*b);
	if (last && last->order == info->next)
	{
		rrb(NULL, b);
		ft_list_add_back(comms, ft_list_new(RRB));
	}
}

void	check_top_value(t_stack **a, t_stack **b, t_info *info, t_stack **comms)
{
	swap_if_next(a, b, info, comms);
	check_bottom_value(b, info, comms);
	while ((*a && (*a)->order == info->next)
		|| (*b && (*b)->order == info->next))
	{
		if (*b && (*b)->order == info->next)
			find_place(a, b, info, comms);
		else
		{
			(*a)->flag = -1;
			ra(a, b);
			ft_list_add_back(comms, ft_list_new(RA));
			info->next++;
		}
		swap_if_next(a, b, info, comms);
		check_bottom_value(b, info, comms);
	}
}
//-------------------------------------------------------------------

//------------------------------------------------------------
int	check_sort(t_list *st_a)//проверка отсартированого списка
{
	while (st_a->next)
	{
		if (st_a->value > st_a->next->value)
			return (0);
		st_a = st_a->next;
	}
	return (1);
} 

//------------------------------------------------------------
int	check_values(t_list *stack, int value)
{
	while (stack)
	{
		if (stack->order >= value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_error(t_list **st_a, t_list **instr)
{
	ft_list_free(st_a);
    if(instr) // проверить на утечки
	    ft_list_free(instr);
	ft_putstr_fd("Error\n", 1);
	return (1);
}


int	ft_first_init_stack_a(int *argc, char *argv, t_list **a) // провекрка одного символа
{
	int		i;
	char	**array;	

	i = 0;
	if (*argc > 2)
		return (i);
	array = ft_split(argv, ' ');
	*argc = array_size(array) + 1;
	i = init_stack(*argc - 1, array, a);
	free_array(array);
	return (i);
}

void	ft_all_free(t_list **st_a, t_list **st_b, t_list **instr)
{
	ft_list_free(st_a);
	ft_list_free(st_b);
	ft_list_free(instr);
}


void	create_array(int (**arr)(t_stack **, t_stack **)) // созндание массива команд
{
	arr[SA] = sa;
	arr[SB] = sb;
	arr[SS] = ss;
	arr[PA] = pa;
	arr[PB] = pb;
	arr[RA] = ra;
	arr[RB] = rb;
	arr[RR] = rr;
	arr[RRA] = rra;
	arr[RRB] = rrb;
	arr[RRR] = rrr;
}

int	init_stack(int size, char **av, t_list **st_a) // проверка подоваймых значений
{
	int	count;

	if (!av)
		return (0);
	while (size > 0)
	{
		size--;
		count = 0;
		if (!ft_check_number(av[size], *st_a, &count))
			return (0);
		ft_list_add_front(st_a, ft_list_new(count));
	}
	return (1);
}

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

t_check	*ft_new_info(int size) // инцилизация структуры инфо
{
	t_check	*info;

	info = malloc(sizeof(t_check));
	if (!info)
		return (NULL);
	info->check_sort = 0;
	info->next_elem = 1;
	info->max = size;
	info->mid = info->max / 2 + info->next_elem;
	return (info);
}

//------------------------------------------------------------