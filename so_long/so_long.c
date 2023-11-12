/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:34:40 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/12 09:49:20 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void memory_alloc()
{
    game_def sl;

    ft_bzero(&sl, sizeof(game_def));
    sl.xpm = calloc(5, sizeof(t_image));
    sl.map_ready = ft_calloc(sl.map_y + 1, sizeof(char *));			
}
void game_init(game_def *sl, char *file_name)
{
	memory_alloc();
	sl->fd
    map_size(sl,map_name);
    read_map(sl, map_name);
	line_sizes(sl);
    if(check_all(sl) != 0)
    {
        printf("map not valid\n"); 
        //error_map(sl);
        exit(1);
    }
	if(check_path(sl) != 0)
		{
			printf("not path\n");
			exit (1);
		}
    sl.mlx_con = mlx_init();
    sl.mlx_win = mlx_new_window(sl.mlx_con, sl.map_x * PIXEL,sl.map_y * PIXEL,"sl");
    xpm_allocation(sl);
	put_in_screen(sl);
    mlx_key_hook(sl.mlx_win, command_input, sl);
    mlx_hook(sl.mlx_win, 17, 0, (void *)exit, 0);
    mlx_loop(sl.mlx_con);

}

int main(int argc, char *argv[])
{
    if(argc != 2)
        return (1);
	memory_alloc();
    game_init(argv[1]);
    return (0);
}
