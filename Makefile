# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 16:01:20 by fde-jesu          #+#    #+#              #
#    Updated: 2023/11/14 19:41:36 by fde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = so_long.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
FUN = sl/so_long.c sl/read_map.c sl/interface.c  sl/commands.c \
		sl/check_map.c sl/check_path.c sl/P_moves.c sl/error_management.c sl/check_all_utils.c
OBJ = ${FUN:.c=.o}
MAKE = make -C
LIBFT = -L libft -lft
MLX = -L mlx -lmlx -Ilmlx -lXext -lX11 -lm 

all: ${NAME}

${NAME}: ${OBJ}
			${MAKE} libft
			${MAKE} mlx
			${CC} ${CFLAGS} -I. ${FUN} ${MLX} ${LIBFT} -o ${NAME} 
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