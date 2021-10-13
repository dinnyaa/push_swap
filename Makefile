SRCS = $(shell find "." -name "*.c" ! -name "checker.c")
SRCS_BONUS = $(shell find "." -name "*.c" ! -name "main.c")
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
NAME = push_swap
NAME_BONUS = checker
CC   = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : ${NAME}

${NAME} : ${OBJS}
	$(MAKE) -C libft
	${CC} ${FLAGS} ${OBJS} -o ${NAME} -Llibft -lft

${NAME_BONUS} : ${OBJS_BONUS}
	$(MAKE) -C libft
	${CC} ${FLAGS}  ${OBJS_BONUS} -o ${NAME_BONUS} -Llibft -lft

bonus : ${NAME_BONUS}

clean :
		${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
		${RM} ${NAME} ${NAME_BONUS}

re : fclean all

re_bonus: fclean bonus

.PHONY : all clean fclean re re_bonus
