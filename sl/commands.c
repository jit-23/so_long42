/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:22:46 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/14 20:03:35 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keys_ws(int key_command, t_game_def *sl)
{
	int	x;
	int	y;

	x = sl->player_x;
	y = sl->player_y;
	if (key_command == 119)
	{
		y--;
		if (sl->map_ready[y][x] == '1')
			return (0);
		if (!player_move(sl, y, x))
			return (0);
	}
	if (key_command == 115)
	{
		y++;
		if (sl->map_ready[y][x] == '1')
			return (0);
		if (!player_move(sl, y, x))
			return (0);
	}
	return (1);
}

int	keys_ad(int key_command, t_game_def *sl)
{
	int	x;
	int	y;

	x = sl->player_x;
	y = sl->player_y;
	if (key_command == 100)
	{
		x++;
		if (sl->map_ready[y][x] == '1')
			return (0);
		if (!player_move(sl, y, x))
			return (0);
	}
	if (key_command == 97)
	{
		x--;
		if (sl->map_ready[y][x] == '1')
			return (0);
		if (!player_move(sl, y, x))
			return (0);
	}
	return (1);
}

int	command_input(int key_command, t_game_def *sl)
{
	if (key_command == 119 || key_command == 115)
		keys_ws(key_command, sl);
	if (key_command == 97 || key_command == 100)
		keys_ad(key_command, sl);
	if (key_command == 65307 || key_command == 113)
		exit_msg(sl, "");
	return (1);
}
