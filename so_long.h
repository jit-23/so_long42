/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:50:55 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/14 20:02:44 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
# define PIXEL 32

typedef struct s_image
{
	void	*img;
	int		x;
	int		y;
}			t_image;

typedef struct t_game_definitions
{
	t_image		*xpm;
	char		*file;
	int			map_x;
	int			map_y;

	char		**map_ready;
	void		*mlx_win;
	void		*mlx_con;

	int			coins;
	int			character;
	int			scape;

	int			player_moves;
	int			player_x;
	int			player_y;
	int			player_y_bf;
	int			player_x_bf;
}	t_game_def;

void	map_size(t_game_def *sl);
void	read_map(t_game_def *sl);
void	xpm_allocation(t_game_def *sl);
void	put_in_screen(t_game_def *sl);
void	exit_game(t_game_def *sl);
int		command_input(int key_command, t_game_def *sl);
void	check_all(t_game_def *sl);
int		check_rectangle(t_game_def *sl);
int		check_components(t_game_def *sl);
int		check_walls(t_game_def *sl);
int		keys_ad(int key_command, t_game_def *sl);
int		keys_ws(int key_command, t_game_def *sl);
int		player_move(t_game_def *sl, int j, int i);
int		flood_fill(t_game_def *sl, char **map_copy, int x, int y);
void	check_path(t_game_def *sl);
void	line_sizes(t_game_def *sl);
void	exit_msg(t_game_def *sl, char *msg);
void	delete_map(t_game_def *sl);
void	delete_xpm(t_game_def *sl);
int		close_w(t_game_def *sl);
#endif
