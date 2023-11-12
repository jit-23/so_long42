/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:15:50 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/12 09:56:46 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void map_size(game_def *sl)
{
	char	*line;
	int fd;

	line = (char *)1;
	fd = open(sl->file, O_RDONLY);
    if (fd < 0)
	    return ;
	//exit_error(sl, "Couldn't open the requested file.");
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
int read_map(game_def *sl)
{
    int		i;
	char    *map_line;
	i = 0;
	int fd;
    fd = open(sl->file,O_RDONLY);
    if (fd < 0)
		return (1);
	while (i < sl->map_x)
	{
		map_line = get_next_line(fd);
     	if (!map_line)
			return(1);//exit_error(sl, "Couldn't read map.");
		sl->map_ready[i] = ft_strtrim(map_line, "\n");
        if (!sl->map_ready[i])
		    return(1);//exit_error(sl, "Couldn't read map.");
		free(map_line);
	i++;
    }
    close(fd);
    return (0);
}