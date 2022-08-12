SRCS	= ft_itoa.c ft_prints.c ft_read.c ft_splitting.c ft_strs.c ft_valid_dict.c input_parse_triada.c

OBJS	= ${SRCS:.c=.o}	 

NAME	= ft_read

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra -g

.c.o:
	${CC} ${CFLAGS} -c $<  -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}


clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all


.PHONY:		all clean fclean re
