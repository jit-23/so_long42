/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 01:28:22 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/12 09:34:57 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void xpm_allocation(game_def *sl)
{
    sl->xpm[0].img = mlx_xpm_file_to_image(sl->mlx_con,"textures/grass.xpm",&(sl->xpm[0].x),&(sl->xpm[0].y));
    sl->xpm[1].img = mlx_xpm_file_to_image(sl->mlx_con,"textures/wall.xpm",&(sl->xpm[1].x),&(sl->xpm[1].y));
    sl->xpm[2].img = mlx_xpm_file_to_image(sl->mlx_con,"textures/exit.xpm",&(sl->xpm[2].x),&(sl->xpm[2].y));
    sl->xpm[3].img = mlx_xpm_file_to_image(sl->mlx_con,"textures/Star.xpm",&(sl->xpm[3].x),&(sl->xpm[3].y));
    sl->xpm[4].img = mlx_xpm_file_to_image(sl->mlx_con,"textures/Fox.xpm",&(sl->xpm[4].x),&(sl->xpm[4].y));
    
}
static void player_info(game_def *sl,int y, int x)
{
	mlx_put_image_to_window(sl->mlx_con,sl->mlx_win,sl->xpm[4].img,x * PIXEL, y * PIXEL);
                    sl->player_x = x;
                    sl->player_y = y;
}
void put_in_screen(game_def *sl)
{
    int x;
    int y;
	static int moves;

    y = 0;
    printf("moves done: %d\n",moves++);
    while (y < sl->map_y) // y < sl->map_y    sl->map_ready[y]
     {
        x = 0;
        while( x < sl->map_x) // sl->map_ready[y][x] x < sl->map_x
        {   
            if (sl->map_ready[y][x] == '0')
                mlx_put_image_to_window(sl->mlx_con,sl->mlx_win,sl->xpm[0].img,x * PIXEL, y * PIXEL);
            if (sl->map_ready[y][x] == '1')
                mlx_put_image_to_window(sl->mlx_con,sl->mlx_win,sl->xpm[1].img,x * PIXEL, y * PIXEL);
            if (sl->map_ready[y][x] == 'E')
                mlx_put_image_to_window(sl->mlx_con,sl->mlx_win,sl->xpm[2].img,x * PIXEL, y * PIXEL);
            if (sl->map_ready[y][x] == 'C')
                mlx_put_image_to_window(sl->mlx_con,sl->mlx_win,sl->xpm[3].img,x * PIXEL, y * PIXEL);
            if (sl->map_ready[y][x] == 'P')
                    player_info(sl,y,x);
            x++;
        }
        y++;
    } 
}
