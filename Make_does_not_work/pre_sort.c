#include "push_swap.h"

// void	sw(int *a, int *b) // переименовать в swap_point
// {
// 	int	c;

// 	c = *a;
// 	*a = *b;
// 	*b = c;
// }

static void	ft_fill_mass(int *mass, int **point, t_list *st_a)
{
	int	i;

	i = 0;
	while (st_a)
	{
		mass[i] = st_a->value;
		point[i] = &(st_a->order);
		st_a = st_a->next;
		i++;
	}
}

static void	ft_init_order(int	**point, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		*point[i] = i + 1;
		i++;
	}
}

static void	ft_order_sort(int *mass, int **point, int size) //предсортировка (пузырьком)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (mass[j] < mass[min])
				min = j;
			j++;
		}
		ft_swap(&mass[i], &mass[min]);
		ft_swap((int *)&point[i], (int *)&point[min]);
		i++;
	}
}

void	pre_sort(t_list *st_a, int size) // переименовать в предсортировку
{
	int	*mass;
	int	**point;

	mass = malloc(sizeof(int) * size);
	point = malloc(sizeof(int *) * size);
	ft_fill_mass(mass, point, st_a); // заполнение массива
	ft_order_sort(mass, point, size); // предсортировка
	ft_init_order(point, size); //заполнение ордер
	free(mass);
	free(point);
	
}