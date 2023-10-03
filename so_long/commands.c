/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:04:47 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/10/03 16:31:55 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void exit_window(game_def *so_long)
{
	int	line;

	line = 0;
	if (so_long->mlx_window)
		mlx_destroy_window(so_long->mlx_connect, so_long->mlx_window);
	free(so_long->mlx_connect);
	while (line < so_long->map_y - 1)
		free(so_long->map_ready[line++]);
	free(so_long->map_ready);
	exit(0);
}

int command_input(int key_command, game_def *so_long)
{
    //int key;
	printf("...%d\n", key_command);
    if (key_command == 65307|| key_command == 113 )
        exit_window(so_long);
    
    
    return (1);
}