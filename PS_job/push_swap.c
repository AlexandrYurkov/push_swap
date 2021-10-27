#include "push_swap.h"

t_ps *ft_stuct_init(t_ps *main_struct, t_list **check)
{
    main_struct->st_a = *check;
    main_struct->st_b = NULL;
    main_struct->max = (int)(*check)->size;
    main_struct->next_elem = 1;
    main_struct->mid = (main_struct->max/2) + main_struct->next_elem;
    main_struct->mass_operat = malloc(sizeof(int) * 10000000);
    /*
        sa && sb = 1; ss = 2
        pa && pb = 0;
        ra && rb = 3; rr = 6;
        rra && rrb = 4; rrr = 8;
    */
    main_struct->i = 0;
    return (main_struct);
}

int main(int ac, char **av)
{
    t_list *check;
	t_list *tmp_a, *tmp_b;
    t_ps *main_struct;

	int i, j, count;
    int *number;
    int *sorted_mass;

    number = malloc(sizeof(int) * (ac - 1));
    sorted_mass = malloc(sizeof(int) * (ac  - 1));
    main_struct = (t_ps*) malloc(sizeof(t_ps));
	i = 0;
	j = 1;
    printf("stack_size = %d\n", ac-1);
	while (i < ac)
	{
		if (av[j] == NULL)
			break;
		number[i++] = ft_atoi(av[j++]);
	}
	count = i;
    sorted_mass = ft_copi_mass(sorted_mass, number, count);
	i = 0;
	quicksort(sorted_mass, 0, count - 1);
    check = ft_new_list(check, number, count);
    ft_in_order(check, sorted_mass);
    main_struct = ft_stuct_init(main_struct, &check);
    // tmp = main_struct->st_a;
    // while (tmp)
    // {
    //     printf("\nstack_a: value = %d, order = %zu| ", tmp->value, tmp->order);
    //     tmp = tmp->next;
    // }
    // printf("\n");
   
    ft_one_sort(main_struct);
    ft_print(main_struct);
    ft_sort_stack_b(main_struct);
    main_struct->st_a = tmp_a;
    main_struct->st_b = tmp_b;
   // ft_sort_stack_b(main_struct);
    ft_print(main_struct);
    
       
   ft_free_list(main_struct->st_a);//переписать функцию очистки структуры main_struct
  //  ft_free_list(check);
   // ft_free_list(main_struct->st_b);
    free(main_struct->mass_operat);
    free(main_struct);
    free(check);
    free(number);
    free(sorted_mass);
    return (0);
}
