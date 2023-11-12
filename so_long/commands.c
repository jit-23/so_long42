/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:22:46 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/12 10:50:03 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../so_long.h"

void error_map(game_def *sl)
{
	int	i;

	i = 0;
	while (i < sl->map_y - 1)
		free(sl->map_ready[i++]);
	exit(EXIT_FAILURE);
}
void exit_window(game_def *sl)
{
	int	i;

	i = 0;
	if (sl->mlx_win)
		mlx_destroy_window(sl->mlx_con, sl->mlx_win);
	if (sl->mlx_con)
        free(sl->mlx_con);
	while (i < sl->map_y - 1)
		free(sl->map_ready[i++]);
	exit(0);
}

int command_input(int key_command, game_def *sl)
{
    //int key;
	//printf("...%d\n", key_command);
	if (key_command == 65362 || key_command == 65364)
		keys_ws(key_command,sl);
	if (key_command == 65361 || key_command == 65363)
		keys_ad(key_command, sl);
    if (key_command == 65307 || key_command == 113)
        exit_window(sl);
    return (1);
}