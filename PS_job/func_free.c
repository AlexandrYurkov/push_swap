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

void ft_free_list(t_list **check)
{
	int i;

	i = 0;
	t_list *tmp;
	t_list *tmp_a;
	tmp = *check;

	if (*check)
    {
        tmp = *check;
        while (tmp)
        {
            tmp_a = tmp->next;
            free(tmp);
            tmp_a = tmp;
        }
    }
/*
	while (tmp)
	{
		tmp = (*check)->next;

		
	}
	
	while (i > 0)
	{
		ft_pop_back(&check);
		i--;
	}*/
}

t_list	*ft_pop_front(t_list **check)
{
	t_list	*tmp_list;
	t_list *tmp_head;

	tmp_list = (*check);
	if (tmp_list)
	{
		tmp_head = tmp_list->next;
		if (tmp_head) {
			tmp_head->prev = NULL;
			(*check) = tmp_head;
		}
		else 
		{
			*check = NULL;
		}

	}
	return (*check);
}