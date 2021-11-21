#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				order;
	int				sort;
}					t_list;

typedef struct s_check
{
	int			max;
	int			mid;
	int			next_elem;
	int			check_sort;
}				t_check;

enum e_content // перечесление целочисленные 
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};
// ---------------
t_list		*ft_list_new(int content); // создание первого листа в списке и инцилизация
void		ft_list_add_front(t_list **list, t_list *new); // добавить вперед списка
int			ft_list_size(t_list *list); // размер списка
t_list		*ft_list_last(t_list *list); // перейти на последний лист
void		ft_list_add_back(t_list **list, t_list *new); // добавить лист в конец списка
void		ft_list_del_head(t_list *list); //удаление одно листа
void		ft_list_del_next(t_list **list);// удаление головы списка
void		ft_list_free(t_list **list); // ? удаление всего списка
void		ft_init_list(t_list *list, void (*f)(int)); // составитель списка
void		free_array(char **array);// в либу
int			array_size(char	**array); // в либу считать 2х_мерный массив // из сплита

int			ft_atoi(const char *str); // из char в int
int			ft_isdigit(int c); // проверка числа
void		ft_putstr_fd(char *s, int fd); // преместить в либу
size_t		ft_strlen(const char *s); // переместить в либу
void		*ft_memset(void *b, int c, size_t len); // в либу
int			ft_strncmp(const char *s1, const char *s2, size_t n);// в либу
char		**ft_split(char const *s, char c);// в либу
char		*ft_strchr(const char *s, int c);// в либу
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);// в либу
void		*ft_calloc(size_t count, size_t size);// в либу

// преместить это все в либу

// основные команды
int			sa(t_list **a, t_list **b); // swap a поменять местами 2(первых) значения в топе стека
int			sb(t_list **a, t_list **b); // swap b
int			pa(t_list **a, t_list **b); // переместить из стека b в стек a
int			pb(t_list **a, t_list **b); // переместить из стека а в стек б
int			ra(t_list **a, t_list **b);// из топа в хвост стеке а
int			rb(t_list **a, t_list **b);// из топа в хвост стеке б
int			rra(t_list **a, t_list **b);// из хвоста в топ стеке а
int			rrb(t_list **a, t_list **b);// из хвоста в топ стеке б
int			ss(t_list **a, t_list **b); // swap a and b // в коде нет функции
int			rr(t_list **a, t_list **b);// из топа в хвост стеке а и б // перпроверить по коду
int			rrr(t_list **a, t_list **b);// из хвоста в топ стеке а и б // перпроверить по коду их нет

//---------------------

void		sort(t_list *stack, int size); // предсортировка и заполнение ордера
void		stack_sort(t_list **a, int size);// основная сортировка
void		mini_stack_sort(t_list **a, int size); // сортировка малого стека

t_check		*ft_infonew(int size); // инцилизация структуры инфо
void		create_array(int (**arr)(t_list **, t_list **)); //созндание массива команд
int			fill_stack(int size, char **nums, t_list **a); // заполнение стека а и проверка значений


int			ft_check_nums(char *argv, t_list *a, int *num);// проверка подоваймых значений
int			check_values(t_list *s, int value);//проверка значения,???
int			check_one_argv(int *argc, char *argv, t_list **a);// заполнение первого элемента ????
void		check_top_value(t_list **a, t_list **b, t_check *info,
				t_list **comms); // проверка топ стека со следующим значением (оптимизация основного кода)

void		replace(t_list	**comms);// замена команд перед выводом(оптимизация)
void		output(t_list	*comms); // вывод команд в консоль
int			is_sorted(t_list *a); // проверка отсортированного стека а

int			ft_error(t_list **a, t_list **comms); // очищение стека а, вывод в консоль error
void		clear_all(t_list **a, t_list **b, t_list **comms); // очистка всех стеков

#endif
