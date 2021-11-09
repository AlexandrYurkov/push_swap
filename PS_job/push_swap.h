#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct b_list
{
	struct b_list *next;
	struct b_list *prev;
	int value;
    size_t order; //сортировка от 0 до max_int, c шагом 1 
	size_t size; //size list (поменть на int)
	int sort;
	int count;
} t_list;

typedef struct push_swap
{
	int max;
	int mid;
	int next_elem;
	t_list *st_a;
	t_list *st_b;
	int *mass_operat;
	int i;
} t_ps;

t_list *ft_lstnew(int value);
t_list *push_back(int value, t_list *check);
t_list *push_front(int value, t_list *check);
void swap_list(t_list *check);
void quicksort(int *number, int first, int last);
int	ft_atoi(const char *str);
int *ft_copi_mass(int *sorted_mass, int *number, int count);
t_list *ft_new_list(t_list *check, int *number, int count);
void ft_in_order(t_list *check, int *sorted_mass);
t_list	*stack_top(t_list *check);
void ft_pop_back(t_list **check);
t_ps *ft_stuct_init(t_ps *main_struct, t_list **check);
void ft_push_b(t_list **st_a, t_list **st_b);
void ft_push_a(t_list **st_a, t_list **st_b, int i);
void ft_free_list(t_list **check);
// написать функцию очистки листов.
void ft_one_sort(t_ps *main_struct);
t_list	*ft_pop_front(t_list **check);
void	do_rra(t_list **stack_a);
void	do_ra(t_list **stack_a);
int count_check (t_list *check);
void ft_print(t_ps *main_struct); // незабыть перепесать.
void ft_sort_stack_b(t_ps *main_struct);
int max_elem(t_list *check);

#endif
