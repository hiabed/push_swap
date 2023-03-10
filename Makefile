NAME = push_swap

CFILES = push_swap.c instructions.c sort_numbers.c ./libft/ft_split.c ./libft/ft_isdigit.c ./libft/ft_atoi.c ./libft/ft_strncmp.c ./libft/ft_strlen.c

OBJ = ${CFILES:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAGS} ${CFILES} -o ${NAME}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

