#include "push_swap.h"

static int ft_max(int n)
{
	if (n == 1)
		return (-1);
	else
		return (0);
}

int ft_atoi(const char *str)
{
	int i;
	int n;
	unsigned int res;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		str++;
	res = 0;
	if (str[0] == '-')
		n = -1;
	else
		n = 1;
	if (str[0] == '-' || str[0] == '+')
		str += 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (i > 10 || res >= 4294967295)
		return (ft_max(n));
	return (n * res);
}

void quicksort(int *number, int first, int last)
{
	int i, j, pivot, temp;
	int *tmp;

	tmp = number;
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (tmp[i] <= tmp[pivot] && i < last)
				i++;
			while (tmp[j] > tmp[pivot])
				j--;
			if (i < j)
			{
				temp = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = temp;
			}
		}

		temp = tmp[pivot];
		tmp[pivot] = tmp[j];
		tmp[j] = temp;
		quicksort(tmp, first, j - 1);
		quicksort(tmp, j + 1, last);
	}
	number = tmp;
}

void ft_one_sort(t_ps *main_struct)
{
	int i, j;
	t_list *tmp_a;
	t_list *tmp_b;

	i = main_struct->max;
	j = main_struct->mid;
	tmp_a = main_struct->st_a;
	while (i > 0)
	{
		if (j < tmp_a->order)
		{
			main_struct->mass_operat[main_struct->i++] = 3;
			tmp_a->sort = 0;
			do_ra(&tmp_a);
		}
		else if (j >= tmp_a->order)
		{
			tmp_a->sort = 1;
			ft_push_b(&tmp_a, &main_struct->st_b);
			tmp_b = stack_top(main_struct->st_b);
			main_struct->mass_operat[main_struct->i++] = 0;
		}
		if (tmp_a->next == NULL)
			break;
		i--;
	}
	main_struct->st_a = tmp_a;
}

void ft_sort_stack_b(t_ps *main_struct)
{
	t_list *tmp;
	int max, i;
	int mid_b;
	int check;

	i = 0;
	tmp = main_struct->st_b;
	check = tmp->sort;
	//-3 1 0 3 4  2| \ / \  7 9 12 14
	while (tmp)
	{
		max = max_elem(tmp);
		mid_b = ((max - main_struct->next_elem) / 2) + main_struct->next_elem;//5
		
		if (mid_b < tmp->order)
		{
			//printf("\n(mid_b < tmp->order) -> |value = %d| |order = %zu|", tmp->value, tmp->order);
			if (tmp->sort < 3)
			{
				tmp->sort = tmp->sort + 1;
				do_ra(&tmp);
			}
			else
				ft_push_a(&main_struct->st_a, &tmp, 0);
		}
		else
		{
			//printf("\n|else -> value = %d| |order = %zu|", tmp->value, tmp->order);
			if ((int)tmp->order == main_struct->next_elem)
			{
				ft_push_a(&main_struct->st_a, &tmp, 1);
				//printf("\n|%zu| next_elen = %d", tmp->order, main_struct->next_elem);
				main_struct->next_elem = main_struct->next_elem + 1;
			}
			else
				ft_push_a(&main_struct->st_a, &tmp, 0);
		}
		
		//printf("\n %d - %zu |max = %d| |mid_b = %d| |next_ elem = %d| |sort = %d|", i, tmp->order, max, mid_b, main_struct->next_elem, tmp->sort);
		i++;
	}

	//ft_free_list(&main_struct->st_b);
}
