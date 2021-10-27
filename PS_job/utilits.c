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