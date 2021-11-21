#include "push_swap.h"

void	sw(int *a, int *b) // переименовать в swap_point
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	fill_array(int *array, int **links, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i] = stack->content;
		links[i] = &(stack->order);
		stack = stack->next;
		i++;
	}
}

void	fill_order(int	**links, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		*links[i] = i + 1;
		i++;
	}
}

void	selection_sort(int *array, int **links, int size) //предсортировка (пузырьком)
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
			if (array[j] < array[min])
				min = j;
			j++;
		}
		sw(&array[i], &array[min]);
		sw((int *)&links[i], (int *)&links[min]);
		i++;
	}
}

void	sort(t_stack *stack, int size) // переименовать в предсортировку
{
	int	*array;
	int	**links;

	array = malloc(sizeof(int) * size);
	links = malloc(sizeof(int *) * size);
	fill_array(array, links, stack); // заполнение массива
	selection_sort(array, links, size); // предсортировка
	fill_order(links, size); //заполнение ордер
	free(array);
	free(links);
	
}
