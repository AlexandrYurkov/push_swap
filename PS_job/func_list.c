#include "push_swap.h"

t_list	*stack_top(t_list *check)
{
	t_list	*tmp;

	tmp = check;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

int count_check (t_list *check)
{
	int i;
	t_list *tmp;

	i = 0;
	tmp = check;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list *ft_lstnew(int value)
{
	t_list *check;

	if (!(check = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	check->value = value;
	check->prev = NULL;
	check->next = NULL;
	return (check);
}

t_list *push_back(int value, t_list *check)
{
	t_list *next_node;

	if (!(next_node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	while (check->next)
    {
        check = check->next;
    }
	next_node->value = value;
	next_node->prev = check;
	next_node->next = NULL;
	check->next = next_node;
	return (next_node);
}

t_list *push_front(int value, t_list *check)
{
	t_list *new_node;
	if (!(new_node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = check;
	check->prev = new_node;
	return (new_node);
}
void	do_rra(t_list **stack_a)
{
    t_list *tmp;
        tmp = stack_top(*stack_a);
        tmp->prev->next = NULL;
        tmp->prev = NULL;
        (*stack_a)->prev = tmp;
        tmp->next = *stack_a;
        *stack_a = tmp;  
}
void	do_ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;
	t_list *end;

	head = (*stack_a)->next;
	tmp = (*stack_a);// начало
	if(head)
		head->prev = NULL;
	end = stack_top(*stack_a);
	end->next = tmp;
	tmp->prev = end;
	tmp->next = NULL;
	(*stack_a) = head;
}


void swap_list(t_list *check) //sa && sb && ss
{
	t_list *tmp;
	tmp = check;
	int c;

	while (tmp->next)
		tmp = tmp->next;
	c = tmp->value;
	tmp->value = tmp->prev->value;
	tmp->prev->value = c;
}

t_list *ft_new_list(t_list *check, int *number, int count) // создание стека а
{
	int i;
	t_list *tmp;

	i = 0;
	tmp = ft_lstnew(number[i++]);
	check = tmp;
	while (i < count)
	{
		push_back(number[i++], tmp);
		check->size = (size_t)count;
		check->count = 0;
	}
	// сколько перекинули в стек б
	return (check);
}

void ft_in_order(t_list *check, int *sorted_mass) // запись order
{
	t_list *tmp;
	int i;
	int j;

	tmp = check;
	while (tmp)
	{
		i = 0;
		while (i < check->size)
		{
			if (sorted_mass[i] == tmp->value)
			{
				tmp->order = (size_t)i + 1;
				break;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void ft_push_a(t_list **st_a, t_list **st_b)//pa
{
	t_list *tmp;
	tmp = *st_b;
	t_list *tmp_a;

	if(*st_a == NULL)
	{
		(*st_a) = ft_lstnew(tmp->value);
		(*st_a)->count = 1;
		(*st_a)->sort = tmp->sort;
		(*st_a)->order =tmp->order;
		(*st_a)->size = tmp->size;
	}
	else
	{
		push_back(tmp->value, *st_a);
		tmp_a = stack_top(*st_a);
		tmp_a->count += 1;
		tmp_a->sort = tmp->sort;
		tmp_a->order =tmp->order;
		tmp_a->size = tmp->size;
	}
	ft_pop_front(&(*st_b));
	}

void ft_push_b(t_list **st_a, t_list **st_b)//pb
{
	t_list *tmp;
	tmp = *st_a;
	t_list *tmp_b;

	if(*st_b == NULL)
	{
		(*st_b) = ft_lstnew(tmp->value);
		(*st_b)->count = 1;
		(*st_b)->sort = tmp->sort;
		(*st_b)->order =tmp->order;
		(*st_b)->size = tmp->size;
	}
	else
	{
		push_back(tmp->value, *st_b);
		tmp_b = stack_top(*st_b);
		tmp_b->count = tmp_b->prev->count + 1;
		tmp_b->sort = tmp->sort;
		tmp_b->order =tmp->order;
		tmp_b->size = tmp->size;
	}
	ft_pop_front(&(*st_a));
}