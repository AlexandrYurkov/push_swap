#include <stdio.h>
#include <stdlib.h>

typedef struct b_list
{
	struct b_list *next;
	struct b_list *prev;
	int value;
	size_t size;
} t_list;

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

t_list *reverse_rotate_list_tail_becomes_head(t_list *check)
{
	t_list *tmp;
	tmp = check;
	
	while (tmp->next)
		tmp = tmp->next;
	int c = tmp->value;
	check = push_front(c, check);

	tmp->prev->next = NULL;
	free (tmp); 
	return (check);	
}

t_list *rotate_list_head_becomes_tail(t_list *check)
{
	t_list *tmp;
	tmp = check;
	int c = tmp->value;
	while (tmp->next)
		tmp = tmp->next;
	push_back(c, tmp);

	tmp = check;
	tmp->next->prev = NULL;
	tmp = check->next;
	free (check); 
	check = tmp;
	return (check);	
}

void swap_list(t_list *check)
{
	t_list *tmp;
	tmp = check;
	int c;

	while (tmp->next)
		tmp = tmp->next;

	c = check->value;
	tmp->value = tmp->prev->value;
	tmp->prev->value = c;
}

int ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\r' || c == '\f' || c == '\v' || c == '\t');
}

int ft_atoi(const char *str)
{
	long long int res;
	int sign;

	sign = 1;
	res = 0;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? -1 : 1;
	while (*str != '\0' && *str >= 48 && *str <= 57)
	{
		if ((res * 10) < res)
			return ((sign == -1) ? 0 : -1);
		res = res * 10 + (*str++ - '0');
	}
	return (res * sign);
}

void quicksort(int number[25], int first, int last)
{
	int i, j, pivot, temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
			{
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}

		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		quicksort(number, first, j - 1);
		quicksort(number, j + 1, last);
	}
}

int main(int ac, char **av)
{
	t_list *check;
	t_list *tmp;

	int i, count, number[ac], j;
	i = 0;
	j = 1;

	while (i < ac)
	{
		if (av[j] == NULL)
			break;
		number[i++] = ft_atoi(av[j++]);
	}
	number[i] = '\0';
	
	
	count = i;
	i = 0;
	quicksort(number, 0, count - 1);
	while (number[i])
	{
		printf("%d ", number[i]);
		i++;
	}
	printf("\n");
	i = 0;
	check = ft_lstnew(number[i + 1]);
	push_back(number[i + 2], check);
	check = push_front(number[i], check);
	tmp = check;
	while (tmp)
	{
		printf("C- %d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");

	//swap_list(check);
	//check = rotate_list_head_becomes_tail(check);
	//check = reverse_rotate_list_tail_becomes_head(check);
	tmp = check;
	while (tmp)
	{
		printf("D- %d ", tmp->value);
		tmp = tmp->next;
	}
	return 0;
}