/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:31:48 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/14 20:03:58 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	move_set(t_game_def *sl, int coordinate, int y, int x)
{
	if (coordinate == '0')
	{
		sl->map_ready[y][x] = 'P';
		sl->map_ready[sl->player_y_bf][sl->player_x_bf] = '0';
		sl->player_x = x;
		sl->player_y = y;
		sl->player_moves++;
	}
	else if (coordinate == 'C')
	{
		sl->map_ready[y][x] = 'P';
		sl->map_ready[sl->player_y_bf][sl->player_x_bf] = '0';
		sl->player_x = x;
		sl->player_y = y;
		sl->coins--;
		sl->player_moves++;
	}
	else if (coordinate == 'E')
	{
		if (sl->coins != 0)
			return (0);
		exit_msg(sl, "YOU WON!!!!\n");
	}
	return (1);
}

int	player_move(t_game_def *sl, int y, int x)
{
	int	move;

	move = 1;
	sl->player_x_bf = sl->player_x;
	sl->player_y_bf = sl->player_y;
	if (sl->map_ready[y][x] == '0')
	{
		move = move_set(sl, '0', y, x);
		put_in_screen(sl);
	}
	else if (sl->map_ready[y][x] == 'C')
	{
		move = move_set(sl, 'C', y, x);
		put_in_screen(sl);
	}
	else if (sl->map_ready[y][x] == 'E')
		move = move_set(sl, 'E', y, x);
	return (move);
}
