
CFILES =  ft_printf.c ft_printf_utils.c
OFILES = ${CFILES:.c=.o}

FLAGS = -c -Wall -Wextra -Werror
CC = gcc
INC = ft_printf.h
NAME = libftprintf.a

${NAME}: ${OFILES} ${INC}
	@${CC} ${FLAGS} ${CFILES}
	@ar -rc ${NAME} ${OFILES}
clean :
	@rm -rf ${OFILES}
fclean : clean
	@rm -rf ${NAME}
re : fclean all
all : ${NAME}