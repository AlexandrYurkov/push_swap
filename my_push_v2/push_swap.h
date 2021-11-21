#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list//s_stack
{
	int				value; //content;
	struct s_list	*next;
	int				order;
	int				sort; //flag;
}					t_list; //t_list;

typedef struct s_check
{
	int			max;
	int			mid;
	int			next_elem; //next;
	int			check_sort; //flag;
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
	t_list	*ft_lstnew(int content); // создание первого листа в списке и инцилизация
	void	ft_list_add_front(t_list **list, t_list *new); // добавить вперед списка
	int	ft_list_size(t_list *list); // размер списка
	t_list	*ft_list_last(t_list *list); //++++ перейти на последний лист
	void	ft_list_add_back(t_list **list, t_list *new); // ++++добавить лист в конец списка

	void	ft_list_delete(t_list *list); //удаление одно листа
	void	ft_list_del_next(t_list **list);// удаление головы списка
	void	ft_list_free(t_list **list); // ? удаление всего списка
	void	ft_list_back(t_list *list, void (*f)(int)); // составитель списка
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
int			sa(t_list **st_a, t_list **st_b); // swap a поменять местами 2(первых) значения в топе стека
int			sb(t_list **st_a, t_list **st_b); // swap b
int			pa(t_list **st_a, t_list **st_b); // переместить из стека b в стек a
int			pb(t_list **st_a, t_list **st_b); // переместить из стека а в стек б
int			ra(t_list **st_a, t_list **st_b);// из топа в хвост стеке а
int			rb(t_list **st_a, t_list **st_b);// из топа в хвост стеке б
int			rra(t_list **st_a, t_list **st_b);// из хвоста в топ стеке а
int			rrb(t_list **st_a, t_list **st_b);// из хвоста в топ стеке б
int			ss(t_list **st_a, t_list **st_b); // swap a and b // в коде нет функции
int			rr(t_list **st_a, t_list **st_b);// из топа в хвост стеке а и б // перпроверить по коду
int			rrr(t_list **st_a, t_list **st_b);// из хвоста в топ стеке а и б // перпроверить по коду их нет
//void		array_output(t_list *stack, int size); // не понятно зачем
//---------------------

	void	pre_sort(t_list *st_a, int size); // предсортировка и заполнение ордера

void		stack_sort(t_list **a, int size);// основная сортировка
	void		mini_sort(t_list **st_a, int size); // сортировка малого стека
	t_check	*ft_new_info(int size);// инцилизация структуры инфо
void		create_array(int (**arr)(t_list **, t_list **)); //созндание массива команд
	int	init_stack(int size, char **av, t_list **a); // заполнение стека а и проверка значений


	int	ft_check_number(char *argv, t_list *a, int *i);// проверка подоваймых значений
int			check_values(t_list *s, int value);//проверка значения,???
	int	ft_first_init_stack_a(int *argc, char *argv, t_list **a);// заполнение первого элемента ????
void		check_top_value(t_list **a, t_list **b, t_check *info,
				t_list **comms); // проверка топ стека со следующим значением (оптимизация основного кода)

	void	change(t_list **instr);	//void		replace(t_list	**comms);// замена команд перед выводом(оптимизация)
	void	ft_print_instr(t_list	*instr);	//void		output(t_list	*comms); // вывод команд в консоль
	int	check_sort(t_list *st_a); // проверка отсортированного стека а

	int	ft_error(t_list **st_a, t_list **instr); // очищение стека а, вывод в консоль error
	void	ft_all_free(t_list **st_a, t_list **st_b, t_list **instr)	//void		clear_all(t_list **a, t_list **b, t_list **comms); // очистка всех стеков

#endif