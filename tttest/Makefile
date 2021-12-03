NAME = push_swap

SRC_LIBFT = $(shell ls ./ft_libft/*.c)

SRC_TOOLS = $(shell ls ./tools/*.c)

SRC_CHECK = $(shell ls ./fun_check/*.c)

SRC_SORT = mini_sort.c pre_sort.c push_swap.c stack_sort.c

SRC = ${SRC_LIBFT} ${SRC_TOOLS} ${SRC_CHECK} ${SRC_SORT}

HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME):	${HEADER} ${OBJ}
			gcc -o ${NAME} ${OBJ}
%.o:	%.c
		gcc ${CFLAGS} -I./ -c $< -o $@
clean:
		rm -f ${OBJ}
fclean:	clean
		rm -f ${NAME}
re:	fclean all

.PHONY:	all clean fclean re