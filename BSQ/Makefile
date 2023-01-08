# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 21:20:03 by juykim            #+#    #+#              #
#    Updated: 2022/09/15 05:00:20 by yongjale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

SRCS	= main.c set_condition.c read_file.c map.c array_free.c write_map.c write_make_map.c error.c

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS}

%.o : %.c
			${CC} ${CFLAGS} -c $^ -o $@ -I ./includes

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re:			fclean all
