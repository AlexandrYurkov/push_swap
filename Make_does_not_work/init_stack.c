#include "push_swap.h"

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
