#include "push_swap.h"

int *ft_copi_mass(int *sorted_mass, int *number, int count)
{
    int i;
    i = 0;
    while (i < count)
    {
        sorted_mass[i] = number[i];
        i++;
    }
    return (sorted_mass);
}

int max_elem(t_list *check)
{
    t_list *tmp;
    int i;
    int j;
    
    tmp = check;
    i = 0;
    j = 0;
    while (tmp)
    {
        i += (int)tmp->order;
        tmp = tmp->next;
        j++;
    }
    i = i/j;
    return(i);
}