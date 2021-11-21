#ifndef LIBFT_H
# define LIBFT_H

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

int	array_size(char	**array);
void	free_array(char **array);
int	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int	ft_isdigit(int c);
void	ft_list_add_back(t_list **list, t_list *news);
void	ft_list_add_front(t_list **list, t_list *news);
void	ft_list_back(t_list *list, void (*f)(int));
void	ft_list_del_next(t_list **list);
void	ft_list_delete(t_list *list);
void	ft_list_free(t_list **list);
t_list	*ft_list_last(t_list *list);
t_list	*ft_list_new(int content);
int	ft_list_size(t_list *list);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_swap(int *a, int *b);


#endif