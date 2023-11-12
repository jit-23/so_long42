/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:15:50 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/12 09:43:40 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void map_size(game_def *so_long, char *map_name)
{
	char	*line;
	int fd;

	line = (char *)1;
	fd = open(map_name, O_RDONLY);
    if (fd < 0)
	    return ;
	//exit_error(so_long, "Couldn't open the requested file.");
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		so_long->map_x = ft_strlen(line);
		so_long->map_y++;
	}
    free(line);
	close(so_long->fd);
	
}
int read_map(game_def *so_long, char *map)
{
    int		i;
	char    *map_line;
	i = 0;
    so_long->fd = open(map,O_RDONLY);
    if (so_long->fd < 0)
		return (1);
	while (i < so_long->map_x)
	{
		map_line = get_next_line(so_long->fd);
     	if (!map_line)
			return(1);//exit_error(so_long, "Couldn't read map.");
		so_long->map_ready[i] = ft_strtrim(map_line, "\n");
        if (!so_long->map_ready[i])
		    return(1);//exit_error(so_long, "Couldn't read map.");
		free(map_line);
	i++;
    }
    close(so_long->fd);
    return (0);
}