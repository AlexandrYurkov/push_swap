#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				order;
	int				flag;
}					t_stack;

typedef struct s_info
{
	int			max;
	int			mid;
	int			next;
	int			flag;
}				t_info;

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
t_stack		*ft_lstnew(int content); // создание первого листа в списке и инцилизация
void		ft_lstadd_front(t_stack **lst, t_stack *new); // добавить вперед списка
int			ft_lstsize(t_stack *lst); // размер списка
t_stack		*ft_lstlast(t_stack *lst); // перейти на последний лист
void		ft_lstadd_back(t_stack **lst, t_stack *new); // добавить лист в конец списка
void		ft_lstdelone(t_stack *lst); //удаление одно листа
void		ft_lstdel_next(t_stack **lst);// удаление головы списка
void		ft_lstclear(t_stack **lst); // ? удаление всего списка
void		ft_lstiter(t_stack *lst, void (*f)(int)); // составитель списка
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
int			sa(t_stack **a, t_stack **b); // swap a поменять местами 2(первых) значения в топе стека
int			sb(t_stack **a, t_stack **b); // swap b
int			pa(t_stack **a, t_stack **b); // переместить из стека b в стек a
int			pb(t_stack **a, t_stack **b); // переместить из стека а в стек б
int			ra(t_stack **a, t_stack **b);// из топа в хвост стеке а
int			rb(t_stack **a, t_stack **b);// из топа в хвост стеке б
int			rra(t_stack **a, t_stack **b);// из хвоста в топ стеке а
int			rrb(t_stack **a, t_stack **b);// из хвоста в топ стеке б


// лишний код (проверить)
/*
int			ss(t_stack **a, t_stack **b); // swap a and b // в коде нет функции
int			rr(t_stack **a, t_stack **b);// из топа в хвост стеке а и б // перпроверить по коду
int			rrr(t_stack **a, t_stack **b);// из хвоста в топ стеке а и б // перпроверить по коду их нет
void		array_output(t_stack *stack, int size); // не понятно зачем
*/
//---------------------

void		sort(t_stack *stack, int size); // предсортировка и заполнение ордера
void		stack_sort(t_stack **a, int size);// основная сортировка
void		mini_stack_sort(t_stack **a, int size); // сортировка малого стека

t_info		*ft_infonew(int size); // инцилизация структуры инфо
void		create_array(int (**arr)(t_stack **, t_stack **)); //созндание массива команд
int			fill_stack(int size, char **nums, t_stack **a); // заполнение стека а и проверка значений


int			ft_check_nums(char *argv, t_stack *a, int *num);// проверка подоваймых значений
int			check_values(t_stack *s, int value);//проверка значения,???
int			check_one_argv(int *argc, char *argv, t_stack **a);// заполнение первого элемента ????
void		check_top_value(t_stack **a, t_stack **b, t_info *info,
				t_stack **comms); // проверка топ стека со следующим значением (оптимизация основного кода)

void		replace(t_stack	**comms);// замена команд перед выводом(оптимизация)
void		output(t_stack	*comms); // вывод команд в консоль
int			is_sorted(t_stack *a); // проверка отсортированного стека а

int			ft_error(t_stack **a, t_stack **comms); // очищение стека а, вывод в консоль error
void		clear_all(t_stack **a, t_stack **b, t_stack **comms); // очистка всех стеков

#endif
