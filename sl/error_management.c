/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 02:33:45 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/14 20:03:42 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_w(t_game_def *sl)
{
	exit_game(sl);
	exit (0);
}

void	exit_msg(t_game_def *sl, char *msg)
{
	ft_printf("%s", msg);
	exit_game(sl);
	exit (0);
}

void	delete_xpm(t_game_def *sl)
{
	if (sl->xpm[0].img)
	{
		mlx_destroy_image(sl->mlx_con, sl->xpm[0].img);
		mlx_destroy_image(sl->mlx_con, sl->xpm[1].img);
		mlx_destroy_image(sl->mlx_con, sl->xpm[2].img);
		mlx_destroy_image(sl->mlx_con, sl->xpm[3].img);
		mlx_destroy_image(sl->mlx_con, sl->xpm[4].img);
	}
	free(sl->xpm);
}

void	delete_map(t_game_def *sl)
{
	int	j;

	j = 0;
	while (j < sl->map_y)
	{
		free(sl->map_ready[j]);
		j++;
	}
	free(sl->map_ready);
}

void	exit_game(t_game_def *sl)
{
	if (sl->map_ready)
		delete_map(sl);
	if (sl->xpm)
		delete_xpm(sl);
	if (sl->mlx_win)
		mlx_destroy_window(sl->mlx_con, sl->mlx_win);
	if (sl->mlx_con)
	{
		mlx_destroy_display(sl->mlx_con);
		free(sl->mlx_con);
	}
}
