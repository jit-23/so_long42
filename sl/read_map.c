/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:15:50 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/14 20:04:05 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_size(t_game_def *sl)
{
	char	*line;
	int		fd;

	fd = open(sl->file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		exit_msg(sl, "Can't open file.\n");
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		sl->map_x = ft_strlen(line);
		sl->map_y++;
		free(line);
	}
	close(fd);
}

void	read_map(t_game_def *sl)
{
	int		i;
	int		fd;
	char	*map_line;

	map_line = "";
	i = 0;
	fd = open(sl->file, O_RDONLY);
	if (fd < 0 || !fd)
		exit_msg(sl, "Can't open file.\n");
	while (i < sl->map_x)
	{
		map_line = get_next_line(fd);
		if (i < 4 && !map_line)
			exit_msg(sl, "Empty map.\n");
		if (!map_line)
			break ;
		sl->map_ready[i] = ft_strtrim(map_line, "\n");
		if (!sl->map_ready[i])
			exit_msg(sl, "Can't read map.\n");
		free(map_line);
		i++;
	}
	close(fd);
}
