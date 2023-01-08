# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 21:03:25 by yongjale          #+#    #+#              #
#    Updated: 2022/09/12 23:16:30 by yongjale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

HEADER = ./includes

%.o	: %.c
			${CC} ${CFLAGS} -c $^ -o $@ -I ${HEADER}
			
all :		${NAME}

${NAME}:	${OBJS}
			ar -cr ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean all
