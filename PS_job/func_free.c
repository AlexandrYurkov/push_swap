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

// void ft_free_list(t_list **check)
// {
// 	int i;

// 	i = 0;
// 	t_list *tmp;
// 	t_list *tmp_a;
// 	tmp = *check;

// 	if (*check)
//     {
//         while (*check)
//         {
//             tmp_a = (*check)->next;
//             free(*check);
//             tmp = tmp_a;
//         }
//     }
// 	else
// 		*check = NULL;

// 	// while (tmp)
// 	// {
// 	// 	tmp = (*check)->next;

		
// 	// }
// 	// while (i > 0)
// 	// {
// 	// 	ft_pop_back(&(*check));
// 	// 	i--;
// 	// }
// }

void ft_free_list(t_ps **frame)
{
    t_list *tmp;
    t_list *st_a;
    t_list *st_b;

    // if ((*frame)->st_a)
    // {
    //     st_a = (*frame)->st_a;
    //     while (st_a)
    //     {
    //         tmp = (st_a)->next;
    //         free(st_a);
    //         st_a = tmp;
    //     }
    // }
    if ((*frame)->st_b)
    {
        st_b = (*frame)->st_b;
        while (st_b)
        {
            tmp = (st_b)->next;
            free(st_b);
            st_b = tmp;
        }
		(*frame)->st_b = NULL;
    }

   // free(*frame);
}

t_list	*ft_pop_front(t_list **check)
{
	t_list	*tmp_list;
	t_list *tmp_head;

	tmp_list = (*check);
	if (tmp_list)
	{
		tmp_head = tmp_list->next;
		if (tmp_head) 
		{
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

// t_list *ft_pop_front(t_list **stack)
// {
//     t_list *tmp;

//     tmp = NULL;
//     if (*stack && (*stack)->next)
//     {
//         tmp = (*stack)->next;
//         (*stack)->prev = NULL;
//     }
// 	else
// 	{
// 		*stack = NULL;
// 	}

//    // free(*stack);
//     return (tmp);
// }