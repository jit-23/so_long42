/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 01:28:22 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/14 20:03:51 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_allocation(t_game_def *sl)
{
	sl->xpm[0].img = mlx_xpm_file_to_image(sl->mlx_con,
			"textures/grass.xpm", &(sl->xpm[0].x), &(sl->xpm[0].y));
	sl->xpm[1].img = mlx_xpm_file_to_image(sl->mlx_con,
			"textures/tree.xpm", &(sl->xpm[1].x), &(sl->xpm[1].y));
	sl->xpm[2].img = mlx_xpm_file_to_image(sl->mlx_con,
			"textures/house.xpm", &(sl->xpm[2].x), &(sl->xpm[2].y));
	sl->xpm[3].img = mlx_xpm_file_to_image(sl->mlx_con,
			"textures/egg.xpm", &(sl->xpm[3].x), &(sl->xpm[3].y));
	sl->xpm[4].img = mlx_xpm_file_to_image(sl->mlx_con,
			"textures/Fox.xpm", &(sl->xpm[4].x), &(sl->xpm[4].y));
}

void	player_info(t_game_def *sl, int y, int x)
{
	mlx_put_image_to_window(sl->mlx_con, sl->mlx_win,
		sl->xpm[4].img, x * PIXEL, y * PIXEL);
}

static void	put_image(t_game_def *sl, int x, int y, char c)
{
	if (c == '0')
		mlx_put_image_to_window(sl->mlx_con, sl->mlx_win,
			sl->xpm[0].img, x * PIXEL, y * PIXEL);
	else if (c == '1')
		mlx_put_image_to_window(sl->mlx_con, sl->mlx_win,
			sl->xpm[1].img, x * PIXEL, y * PIXEL);
	else if (c == 'E')
		mlx_put_image_to_window(sl->mlx_con, sl->mlx_win,
			sl->xpm[2].img, x * PIXEL, y * PIXEL);
	else if (c == 'C')
		mlx_put_image_to_window(sl->mlx_con, sl->mlx_win,
			sl->xpm[3].img, x * PIXEL, y * PIXEL);
}

void	put_in_screen(t_game_def *sl)
{
	int			x;
	int			y;
	static int	moves;

	y = 0;
	ft_printf("moves done: %d\n", moves++);
	while (y < sl->map_y)
	{
		x = 0;
		while (x < sl->map_x)
		{
			if (sl->map_ready[y][x] == '0')
				put_image(sl, x, y, '0');
			if (sl->map_ready[y][x] == '1')
				put_image(sl, x, y, '1');
			if (sl->map_ready[y][x] == 'E')
				put_image(sl, x, y, 'E');
			if (sl->map_ready[y][x] == 'C')
				put_image(sl, x, y, 'C');
			if (sl->map_ready[y][x] == 'P')
				player_info(sl, y, x);
			x++;
		}
		y++;
	}
}
