# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 21:03:25 by yongjale          #+#    #+#              #
#    Updated: 2022/09/14 17:31:58 by yongjale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ./srcs/main.c ./srcs/base.c ./srcs/operate.c ./srcs/value.c

OBJS = ${SRCS:.c=.o}

NAME = do-op

HEADER = ./includes

%.o	: %.c
			${CC} ${CFLAGS} -c $^ -o $@ -I ${HEADER}
			
all :		${NAME}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean all
