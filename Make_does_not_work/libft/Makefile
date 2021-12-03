NAME = libft.a

INCLUDES = ./

HEADER = libft.h

SRCS =	array_size.c free_array.c ft_atoi.c ft_calloc.c ft_isdigit.c ft_memset.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strlcpy.c ft_strncmp.c ft_swap.c 


FLAGS = -Wall -Wextra -Werror -g


OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c 
	gcc -c $(FLAGS) -I $(INCLUDES) -o $@ $<

clean: 
	rm -f $(OBJ) $(BONUS_O)

fclean: clean
	rm -f $(NAME)

re: fclean all bonus clean

.PHONY: all clean fclean re bonus