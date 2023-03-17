NAME = push_swap

CFILES = push_swap.c push_and_pop.c rotate_actions.c sort_2_to_5.c push_to_b.c swap_actions.c errors_handler.c final_sort.c helper_for_final_sort.c ./libft/ft_split.c ./libft/ft_isdigit.c ./libft/ft_atoi.c ./libft/ft_strncmp.c ./libft/ft_strlen.c

OBJ = ${CFILES:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror #-fsanitize=address

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAGS} ${CFILES} -o ${NAME}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

