/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 03:10:00 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/14 20:03:20 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	line_sizes(t_game_def *sl)
{
	int	i;
	int	line_0;
	int	cur_line;

	i = 0;
	if (!sl->map_ready[0])
		exit_msg(sl, "Empty map.\n");
	line_0 = ft_strlen(sl->map_ready[0]);
	if (line_0 == 0)
		exit_msg(sl, "Empty map.\n");
	while (i < sl->map_y)
	{
		cur_line = ft_strlen(sl->map_ready[i]);
		if (cur_line != line_0)
			exit_msg(sl, "Map with uneven lines.\n");
		i++;
	}
}

void	check_all(t_game_def *sl)
{
	if (check_rectangle(sl) != 0)
	{
		exit_msg(sl, "The map is not retangle.\n");
	}
	if (check_components(sl) != 0)
	{
		if (sl->scape != 1)
			exit_msg(sl, "Wrong number of Exits for the map.\n"
				"Allowed only 1 Exit.\n");
		if (sl->character != 1)
			exit_msg(sl, "Wrong number of Players.\n"
				"Allowed only 1 player for the map.\n");
		if (sl->coins < 1)
			exit_msg(sl, "Wrong number of itens to get.\n"
				"At leat 1 iten is needed.\n");
	}
	if (check_walls(sl) != 0)
		exit_msg(sl, "");
}
