/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:15:50 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/13 02:44:25 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_size(game_def *sl)
{
	char	*line;
	int		fd;

	line = "";
	fd = open(sl->file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		sl->map_x = ft_strlen(line);
		sl->map_y++;
	}
	free(line);
	close(fd);
}

int	read_map(game_def *sl)
{
	int		i;
	int		fd;
	char	*map_line;

	map_line = (char *)1;
	i = 0;
	fd = open(sl->file, O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
	while (i < sl->map_x)
	{
		map_line = get_next_line(fd);
		if (!map_line)
			{
				break ;
				//exit_msg(sl,"cant read map\n");
			}
		sl->map_ready[i] = ft_strtrim(map_line, "\n");
		if (!sl->map_ready[i])
		{
			break ;
			//exit_msg(sl,"cant read map\n");
		}
		free(map_line);
		i++;
	}
	close(fd);
	return (0);
}
