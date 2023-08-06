NAME		= calculator
SRCS		= $(shell find . -name "*.c")
OBJS		= ${SRCS:.c=.o}
CC			= gcc
INCLUDES	= $(shell find . -name "*.h")
CFLAGS		= #-Wall -Werror -Wextra
RM			= rm -f

.c.o :
	${CC} ${CFLAGS} -I $(INCLUDES) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME) : ${OBJS}
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) ${OBJS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME} 

re : fclean all

.PHONY : all clean fclean re 