NAME = philo

SRCS	=	main.c\
			ft_init.c\
			utils/ft_atoi.c\
			utils/ft_str_isdigit.c\
			utils/ft_time.c\
			utils/ft_print.c\
			utils/ft_free.c\
			actions/actions.c\
			actions/routine.c\
			threads.c\

			
OBJS	=	${SRCS:.c=.o}
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -pthread #-g -fsanitize=thread #-fsanitize=address


HEADER_MESSAGE = PHILO IS COMPILING${_END}

all:		${NAME}

.c.o:
			@${CC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJS}
			@echo "[${HEADER_MESSAGE}]"
			@${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "philo's ready to be used !"

clean:		
			@echo "Deleting so_long binary files..."
			@rm -f ${OBJS}

fclean:		clean
			@echo "Deleting philo executable..."
			@rm -f ${NAME}
			@echo "philo's has been cleaned !"

re:			fclean all

.PHONY:		all fclean clean all bonus