# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 16:01:20 by fde-jesu          #+#    #+#              #
#    Updated: 2023/11/11 17:59:55 by fde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong.a
HEADER = so_long.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
FUN = so_long/so_long.c so_long/read_map.c so_long/interface.c  so_long/commands.c \
		so_long/check_map.c so_long/check_path.c so_long/P_moves.c
OBJ = ${FUN:.c=.o}
MAKE = make -C
LIBFT = -L libft -lft
MLX = -L mlx -lmlx -Ilmlx -lXext -lX11 -lm 

all: ${NAME}

${NAME}: ${OBJ}
			${MAKE} libft
			${MAKE} mlx
			${CC} ${CFLAGS} -I. ${FUN} ${MLX} ${LIBFT} 
clean:
		rm -f ${OBJ}
		${MAKE} libft clean
		${MAKE} mlx clean
		
fclean:	clean
		rm -f ${NAME}
		${MAKE} libft fclean

re:		fclean all

.PHONY: all clean fclean re
.SILENT: