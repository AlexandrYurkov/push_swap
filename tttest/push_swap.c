#include "push_swap.h"

void	ft_print_instr(t_list	*instr)
{
	char	commands[11][4] = {"sa", "sb", "ss", "pa", "pb", "ra",
	"rb", "rr", "rra", "rrb", "rrr"};

	while (instr)
	{
		ft_putstr_fd((char *)commands[instr->value], 1);
		ft_putstr_fd("\n", 1);
		instr = instr->next;
	}
}

int	free_stack_a(t_list **st_a)
{
	if (st_a && check_sort(*st_a))
	{
		ft_list_free(st_a);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*st_a;

	st_a = NULL;
	if (argc < 2)
		return (0);
	if (!init_stack(argc - 1, argv + 1, &st_a))
		if (!ft_first_init_stack_a(&argc, argv[1], &st_a))
			return (ft_error(&st_a, NULL));
	if (free_stack_a(&st_a))
		return (0);
	argc--;
	pre_sort(st_a, argc);
	if (argc <= 6)
		mini_sort(&st_a, argc);//остановился тут
	else
		stack_sort(&st_a, argc);
}
