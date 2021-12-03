NAME = push_swap

INCLUDES = ./

HEADER = push_swap.h

SRCS =	array_size.c free_array.c ft_atoi.c ft_calloc.c ft_isdigit.c ft_memset.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strlcpy.c ft_strncmp.c ft_swap.c ft_strlen.c \
		error_free.c ft_swap_list.c init_stack.c \
		mini_sort.c pre_sort.c push_swap.c push.c reverse_rotate.c \
		rotate.c stack_sort.c upgrede_instr.c check_value.c init_enum.c \
		ft_list_add_back.c ft_list_add_front.c ft_list_back.c ft_list_del_next.c \
		ft_list_delete.c ft_list_free.c ft_list_last.c ft_list_new.c ft_list_size.c 


FLAGS = -Wall -Wextra -Werror -g


OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c 
	gcc -c $(FLAGS) -I $(INCLUDES) -o $@ 

clean: 
	rm -f $(OBJ) $(BONUS_O)
	
fclean: clean
	rm -f $(NAME)

re: fclean all bonus clean

.PHONY: all clean fclean re bonus