#include "push_swap.h"

void	ft_pop_back(t_list **check)
{
	t_list	*tmp_list;

	tmp_list = stack_top(*check);
	if (tmp_list->prev)
		tmp_list->prev->next = NULL;
	else
		*check = NULL;
	free(tmp_list);
}

void ft_free_list(t_list *check)
{
	int i;

	i = 0;
	t_list *tmp;
	tmp = check;

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	
	while (i > 0)
	{
		ft_pop_back(&check);
		i--;
	}
}

void	ft_pop_front(t_list **check)
{
	t_list	*tmp_list;
	t_list *tmp_head;

	tmp_list = (*check);
	if (tmp_list->next)
		tmp_head = tmp_list->next;
	tmp_head->prev = NULL;
	//free(*check);
	(*check) = tmp_head;
	//free(tmp_list);
}