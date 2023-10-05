SRCS = ft_printf.c ft_print_u_d_i.c ft_print_p_x_X.c ft_print_per_s_c.c ft_flags.c ft_print_wflags.c

OBJS = ${SRCS:.c=.o}

INCLUDES = ./includes

LIB = -L. -libft

ARRC = ar rc

RANLIB = ranlib

NAME = libftprintf.a

REMOVE = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAIN = main.c

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c -I ${INCLUDES} $< -o $@

${NAME}: ${OBJS}
	${ARRC} ${NAME} ${OBJS} libft.a
	${RANLIB} ${NAME}

# test: all ${MAIN}
# 	./a.out

# ${MAIN}:
# 	${CC} ${CFLAGS} main.c -lbsd -L. -lft

clean:
	${REMOVE} ${OBJS}

fclean: clean
	${REMOVE} ${NAME}

re: fclean all

.PHONY: all clean fclean re
