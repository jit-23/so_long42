/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:39:16 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/14 20:03:07 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_rectangle(t_game_def *sl)
{
	if (sl->map_y >= sl->map_x)
		return (1);
	return (0);
}

int	check_walls(t_game_def *sl)
{
	int	i;

	i = 0;
	while (i < sl->map_x)
	{
		if ((sl->map_ready[0][i] != '1'
			|| sl->map_ready[sl->map_y - 1][i] != '1'))
		{
			ft_printf("Invalid horizontal walls.\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < sl->map_y)
	{
		if ((sl->map_ready[i][0] != '1'
			|| sl->map_ready[i][sl->map_x - 1] != '1'))
		{
			ft_printf("Invalid side walls.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static	void	player_loc(t_game_def *sl, int y, int x)
{
	sl->player_x = x;
	sl->player_y = y;
	sl->character++;
}

int	check_components(t_game_def *sl)
{
	int	i;
	int	j;

	j = 0;
	while (j < sl->map_y)
	{
		i = 0;
		while (i < sl->map_x)
		{
			if (sl->map_ready[j][i] == 'P')
				player_loc(sl, j, i);
			else if (sl->map_ready[j][i] == 'E')
				sl->scape++;
			else if (sl->map_ready[j][i] == 'C')
				sl->coins++;
			else if (!(ft_strchr("01", sl->map_ready[j][i])))
				exit_msg(sl, "Unkown character on the map.\n");
			i++;
		}
		j++;
	}
	if (sl->scape != 1 || sl->character != 1 || sl->coins < 1)
		return (1);
	return (0);
}
