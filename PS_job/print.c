#include "push_swap.h"

void ft_print(t_ps *main_struct)
{
    t_list *tmp;
    tmp = main_struct->st_a;
    printf("\n");
    while (tmp)
    {
         printf("\nstack_a: value = %d, order = %zu| size = %zu|  |sort = %d| |count = %d|", tmp->value, tmp->order, tmp->size, tmp->sort, tmp->count);
        tmp = tmp->next;
    }
    printf("\n");
    tmp = main_struct->st_b;
    while (tmp)
    {
        printf("\nstack_b: value = %d, order = %zu| size = %zu|  |sort = %d| |count = %d|", tmp->value, tmp->order, tmp->size, tmp->sort, tmp->count);
        tmp = tmp->next;
    }
}