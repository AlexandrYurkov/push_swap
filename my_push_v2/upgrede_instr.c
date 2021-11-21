#include "push_swap.h"

static int	check_upgrede_instr(t_list *instr, int fact_instr, int next_instr)
{
	return (instr->value == fact_instr && instr->next->value == next_instr);
}

static void	upgrade_instr(t_list **instr, t_list *tmp, int command)
{
	(*instr)->value = command;
	ft_list_del_next(instr);
	*instr = tmp;
}

void	change(t_list **instr)
{
	t_list	*tmp;

	tmp = *instr;
	while (*instr && (*instr)->next)
	{
		if (check_upgrede_instr(*instr, SA, SB) || check_upgrede_instr(*instr, SB, SA))
			upgrade_instr(instr, tmp, SS);
		if (check_upgrede_instr(*instr, RA, RB) || check_upgrede_instr(*instr, RB, RA))
			upgrade_instr(instr, tmp, RR);
		if (check_upgrede_instr(*instr, RRA, RRB)
			|| check_upgrede_instr(*instr, RRB, RRA))
			upgrade_instr(instr, tmp, RRR);
		if ((*instr)->next->next && (check_upgrede_instr((*instr)->next, PA, PB)
				|| check_upgrede_instr((*instr)->next, PB, PA)))
		{
			ft_list_del_next(instr);
			ft_list_del_next(instr);
			*instr = tmp;
			continue ;
		}	
		*instr = (*instr)->next;
	}
	*instr = tmp;
}