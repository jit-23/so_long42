/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:31:48 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/12 10:50:55 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	move_set(game_def *sl, int coordinate, int y, int x)
{
	if (coordinate == '0')
	{
		sl->map_ready[y][x] = 'P';
        sl->map_ready[sl->player_y_bf][sl->player_x_bf] = '0';
        sl->player_x = x;
        sl->player_y = y;
        sl->player_steps++;
	}
	else if (coordinate == 'C')
	{
		sl->map_ready[y][x] = 'P';
        sl->map_ready[sl->player_y_bf][sl->player_x_bf] = '0';
        sl->player_x = x;
        sl->player_y = y;
        sl->coins--;
        sl->player_steps++;
	}
	else if (coordinate == 'E')
	{
		if (sl->coins != 0)
            return (0);
        ft_printf("You won!!!\n");
        exit_window(sl);
	}
	return (1);
}
int    player_move(game_def *sl, int y, int x)
{
	int move;

	move = 1;
	sl->player_x_bf = sl->player_x;
	sl->player_y_bf = sl->player_y;
	if(sl->map_ready[y][x] == '0')
		move = move_set(sl, '0', y, x);
	else if(sl->map_ready[y][x] == 'C')
		move = move_set(sl, 'C', y, x);
	else if (sl->map_ready[y][x] == 'E')
		move = move_set(sl, 'E', y, x);
	put_in_screen(sl);
	return (move);
}

int keys_ws(int key_command,game_def *sl)
{
	int x;
	int y;
	x = sl->player_x;
	y = sl->player_y;
	if (key_command == 65362)
	{
		y--;
		if (sl->map_ready[y][x] == '1')
			return (0);
		if(!player_move(sl, y, x))
			return (0);
	}
	if (key_command == 65364)
	{
		y++;
		if(sl->map_ready[y][x] == '1')
			return (0);
		if(!player_move(sl, y, x))
			return (0);
	}
	return (1);
}

int	keys_ad(int key_command, game_def *sl)
{
	int	x;
	int	y;

	x = sl->player_x;
	y = sl->player_y;
	if (key_command == 65363)
	{
		x++;
		if (sl->map_ready[y][x] == '1')
			return (0);
		if (!player_move(sl, y, x))
			return (0);
	}
	if (key_command == 65361)
	{
		x--;
		if (sl->map_ready[y][x] == '1')
			return (0);
		if (!player_move(sl, y, x))
			return (0);
	}
	return (1);
}
