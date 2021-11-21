#include "push_swap.h"

int	ft_error(t_list **st_a, t_list **instr)
{
	ft_list_free(st_a);
    if(instr) // проверить на утечки
	    ft_list_free(instr);
	ft_putstr_fd("Error\n", 1);
	return (1);
}

void	ft_all_free(t_list **st_a, t_list **st_b, t_list **instr)
{
	ft_list_free(st_a);
	ft_list_free(st_b);
	ft_list_free(instr);
}