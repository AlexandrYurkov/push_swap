#include "push_swap.h"

int	find_command(char *str)
{
	const char	commands[11][4] = {"sa", "sb", "ss", "pa",
	"pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(str, commands[i], 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	read_extra(void)
{
	int	ch;

	while (read(0, &ch, 1) && ch != '\n');
	return (0);
}

int	read_commands(t_list **comms)
{
	char	buf[4];
	int		res;
	int		command;
	int		i;

	res = 1;
	while (res > 0)
	{
		ft_memset(buf, 0, 4);
		i = 0;
		res = read(0, &(buf[i]), 1);
		while (res && buf[i] != '\n' && i < 4)
			res = read(0, &(buf[++i]), 1);
		if (!res && !buf[0])
			break ;
		if (i >= 4)
			return (read_extra());
		buf[i] = 0;
		command = find_command((char *)buf);
		if (command == -1)
			return (0);
		else
			ft_list_add_back(comms, ft_list_new(command));
	}
	return (1);
}

int	checker(t_list **a, t_list **comms)
{
	int		(*comm_funcs[11])(t_list **, t_list **);
	t_list *b;

	create_array(comm_funcs);
	b = NULL;
	while (*comms)
	{
		comm_funcs[(*comms)->value](a, &b);
		*comms = (*comms)->next;
	}
	if (!b && check_sort(*a))
		return (1);
	else
	{
		ft_list_free(&b);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*comms;

	st_a = NULL;
	comms = NULL;
	if (argc < 2)
		return (0);
	if (!init_stack(argc - 1, argv + 1, &st_a))
		if (!ft_first_init_stack_a(&argc, argv[1], &st_a))
			return (ft_error(&st_a, NULL));
	if (!read_commands(&comms))
		return (ft_error(st_a, &comms));
	if (checker(&st_a, &comms))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_all(&st_a, NULL, &comms);
}
