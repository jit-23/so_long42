
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:01:44 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/11 03:07:35 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_path(game_def *sl)
{
    int path;
    char **map_copy;
    int j;

    j = 0;
    map_copy = (char **)malloc(sizeof(char *)  * sl->map_y + 1);
    if (!map_copy)
        return 1;// exit
    while(j < sl->map_y)
    {
		map_copy[j] = ft_strdup(sl->map_ready[j]);
		if (!map_copy[j])
			return 1;
		j++;
	}
    path = flood_fill(sl, map_copy, sl->player_x, sl->player_y);
	return (path);
}

int flood_fill(game_def *sl, char **map, int x, int y)
{
    static int exit_count;
    static int coin_count;
    if (map[y][x] == '1')
        return (0);
    else if (map[y][x] == 'E')
        exit_count++;
    else if (map[y][x] == 'C')
    {
	    coin_count++;
	}
	map[y][x] = '1';
    flood_fill(sl,map,x+1,y);
    flood_fill(sl,map,x-1,y);
    flood_fill(sl,map,x,y+1);
    flood_fill(sl,map,x,y-1);
    if (exit_count == 1 && coin_count == sl->coins)
        return (0);
    return (1);
}
