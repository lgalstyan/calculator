NAME		= calculator
SRCS		= $(shell find . -name "*.c")
OBJS		= ${SRCS:.c=.o}
CC		= cc
CFLAGS		= -Wall -Werror -Wextra
RM		= rm -f

.c.o :
	${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME) : ${OBJS}
	$(CC) $(CFLAGS) -I. -o $(NAME) ${OBJS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME} 

re : fclean all

.PHONY : all clean fclean re 
