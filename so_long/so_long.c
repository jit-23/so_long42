/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:59:43 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/10/03 17:45:56 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

int main(int argc, char **argv)
{
    int i;
    game_def    so_long;

    if (argc != 2)
    {
        printf("wrong number of arguments\n");
        return (0);
    } 
    ft_memset(&so_long,0 ,sizeof(game_def));
    i = ft_strlen(argv[1]) - 1;
    if (argv[1][i - 3] == '.' && argv[1][i - 2] == 'b' && argv[1][i - 1] == 'e' && argv[1][i] == 'r')
        i = read_map(&so_long,argv[1]);
    else
        printf("dam, wrong\n");
    if (check_rectangle(&so_long) == 1)
        printf("wrong size (x/y)\n");
 /*    so_long.mlx_connect = mlx_init();
    so_long.mlx_window = mlx_new_window(so_long.mlx_connect,
                                        so_long.map_x * 50,
                                        so_long.map_y * 50,
                                        "so_long42"); */
    //grafics(&so_long);
    
    so_long.mlx_connect = mlx_init();
	size_window_init(&so_long);
	so_long.mlx_window = mlx_new_window(so_long.mlx_window, so_long.map_width, so_long.map_height , "so_long");
	
    
    xpm_images(&so_long);
    //put_in_screen(&so_long);

    mlx_hook(so_long.mlx_window, 17, 0, (void *)exit, 0);
    mlx_key_hook(so_long.mlx_window, command_input, &so_long);
    
    mlx_loop(so_long.mlx_connect);
    return(0);
}
