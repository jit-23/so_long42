/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 03:10:00 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/12 10:24:20 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	line_sizes(game_def *sl)
{
	int	i;
	int	line_0;
	int	cur_line;

	i = 0;
	line_0 = ft_strlen(sl->map_ready[0]);
	while (i < sl->map_y)
	{
		cur_line = ft_strlen(sl->map_ready[i]);
		if (cur_line != line_0)
		{
			printf("map with uneven line size\n");
			exit(1);
		}
		i++;
	}
}

int	check_rectangle(game_def *sl)
{
	if (sl->map_y >= sl->map_x)
		return (1); // substituir todos os return por uma funcao que apague tudo
	return (0);
}

int	check_walls(game_def *sl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sl->map_x)
	{
		if ((sl->map_ready[0][i] != '1'
			|| sl->map_ready[sl->map_y - 1][i] != '1'))
		{
			printf("no sealing//floor wall\n");
			return (1); // not covered in walls (top and low line)
		}
		i++;
	}
	while (j < sl->map_y)
	{
		if ((sl->map_ready[j][0] != '1'
			|| sl->map_ready[j][sl->map_x -1] != '1'))
		{
			printf("no side walls\n");
			return (1);// not covered in walls (left and right walls) 
		}
		j++;
	}
	return (0);
}

static	void	player_loc(game_def *sl, int y, int x)
{
	sl->player_x = x;
	sl->player_y = y;
	sl->character++;
}

int	check_components(game_def *sl)
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
				return (2); //perror? exit all;
			i++;
		}
		j++;
	}
	if (sl->scape != 1 || sl->character != 1 || sl->coins < 1)
		return (1);
	return (0);
}

void	check_all(game_def *sl)
{
	if (check_rectangle(sl) != 0)
	{
		printf("mapa n retangular\n");
		exit(EXIT_FAILURE);
	}
	if (check_components(sl) != 0)
	{
		printf("componentes falhou \n");
		exit(EXIT_FAILURE);
	}
	if (check_walls(sl) != 0)
	{
		printf("muro sem bordas\n");
		exit(EXIT_FAILURE);
	}
}
