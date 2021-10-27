NAME = ps.a

INCLUDES = ./

HEADER = push_swap.h

SRCS =	push_swap.c func_list.c func_sort.c\


FLAGS = -Wall -Wextra -Werror -g


OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c 
	gcc -c $(FLAGS) -I $(INCLUDES) -o $@ $<

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all bonus clean

.PHONY: all clean fclean re bonus