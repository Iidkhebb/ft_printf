CFILES =  ft_printf.c ft_printf_utils.c
OFILES = ${CFILES:.c=.o}
CBFILES = ft_printf_bonus.c ft_printf_utils_bonus.c ft_strlen.c ft_atoi.c ft_itoa.c
OBFILES = ${CBFILES:.c=.o}
FLAGS = -c -Wall -Wextra -Werror
CC = gcc
INC = ft_printf.h
NAME = libftprintf.a

${NAME}: ${OFILES} ${INC}
	@${CC} ${FLAGS} ${CFILES}
	@ar -rc ${NAME} ${OFILES}
clean :
	@rm -rf ${OFILES} ${OBFILES}
fclean : clean
	@rm -rf ${NAME}
re : fclean all
all : ${NAME}
bonus: ${OBFILES}
	@${CC} ${FLAGS} ${CBFILES}
	@ar -rc ${NAME} ${OBFILES}