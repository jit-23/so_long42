/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:59:43 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/09/21 23:34:08 by fde-jesu         ###   ########.fr       */
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
    {
        printf("keep going\n");
        i = read_map(&so_long,argv[1]);
        if (i == 0)
            printf("error");
    }
    else 
        printf("error, non plausible map\n"); 
    so_long.mlx_connect = mlx_init();
    so_long.mlx_window = mlx_new_window(so_long.mlx_connect,
                                        so_long.map_x * 50,
                                        so_long.map_y * 50,
                                        "so_long42");
    //grafics(&so_long);
    
    xpm_images(&so_long);
    printf("flag2\n");
    put_in_screen(&so_long);
    printf("flag3\n");
    mlx_loop(so_long.mlx_connect);j
    printf("flag4\n");
    return(0);
}