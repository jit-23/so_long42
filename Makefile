# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 16:01:20 by fde-jesu          #+#    #+#              #
#    Updated: 2023/09/21 16:28:20 by fde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong.a
HEADER = so_long.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
FUN =	so_long/so_long.c so_long/map_check.c
OBJ = ${FUN:.c=.o}
MAKE = make -C
LIBFT = -L libft -lft

all: ${NAME}

${NAME}: ${OBJ}
			${MAKE} libft
			${CC} ${CFLAGS} -I. ${FUN} ${LIBFT}
clean:
		rm -f ${OBJ}
		${MAKE} libft clean
		
fclean:	clean
		rm -f ${NAME}
		${MAKE} libft fclean

re:		fclean all

.PHONY: all clean fclean re
#.SILENT: