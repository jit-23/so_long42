/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:01:44 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/14 20:03:28 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	delete_map_copy(char **map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
}

void	check_path(t_game_def *sl)
{
	int		path;
	int		j;
	char	**map_copy;

	j = 0;
	map_copy = (char **)ft_calloc(sl->map_y + 1, sizeof(char *));
	if (!map_copy)
	{
		delete_map_copy(map_copy);
		exit_msg(sl, "Can't allocate mem\n");
	}
	while (j < sl->map_y)
	{
		map_copy[j] = ft_strdup(sl->map_ready[j]);
		if (!map_copy[j])
		{
			delete_map_copy(map_copy);
			exit(1);
		}
		j++;
	}
	path = flood_fill(sl, map_copy, sl->player_x, sl->player_y);
	delete_map_copy(map_copy);
	if (path)
		exit_msg(sl, "Can't find path to exit.\n");
}

int	flood_fill(t_game_def *sl, char **map_copy, int x, int y)
{
	static int	exit_count;
	static int	coin_count;

	if (map_copy[y][x] == '1')
		return (0);
	else if (map_copy[y][x] == 'E')
		exit_count++;
	else if (map_copy[y][x] == 'C')
	{
		coin_count++;
	}
	map_copy[y][x] = '1';
	flood_fill(sl, map_copy, x + 1, y);
	flood_fill(sl, map_copy, x - 1, y);
	flood_fill(sl, map_copy, x, y + 1);
	flood_fill(sl, map_copy, x, y - 1);
	if (exit_count == 1 && coin_count == sl->coins)
		return (0);
	return (1);
}
