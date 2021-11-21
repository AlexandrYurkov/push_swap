#include "push_swap.h"

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