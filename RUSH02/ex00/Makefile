# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjunk <hyunjunk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 14:42:40 by hyunjunk          #+#    #+#              #
#    Updated: 2022/09/11 17:20:14 by hyunjunk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

CC = gcc
CFLAG = -Wall -Wextra

SRCS = ${wildcard srcs/*.c}
OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAG} -c $< -o $@ -I includes

${NAME}: ${OBJS}
	${CC} ${CFLAG} ${OBJS} -o $@

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: clean fclean re