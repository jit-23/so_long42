#include "../so_long.h"

void xpm_images(game_def *so_long)
{
    int image_width;
    int image_height;
    // mlx_put_image_to_window(so_long->mlx_connect,
    //                                         so_long->mlx_window,
    //                                         so_long->floor,
    //                                         so_long->map_x * 100,
    //                                         so_long->map_y * 100);
    
    so_long->floor = mlx_xpm_file_to_image(so_long->mlx_connect,
                                            "textures/grass.xpm", &image_width, &image_height);
    so_long->walls = mlx_xpm_file_to_image(so_long->mlx_connect,
                                            "textures/box.xpm", &image_width, &image_height);
}
void put_in_screen(game_def *so_long)
{
    int x;
    int y;

     y = 0;
    while (y < so_long->map_y)
    {
        x = 0;
        while(x < so_long->map_x)
        {
//                    printf("FLAG....\n");
                   // printf("x - %d || y - %d\n", x, y);
                    printf("array[%d][%d] = %c\n",y,x, so_long->map_ready[y][x]);

           /*  if (so_long->map_ready[x][y] == '0')
                mlx_put_image_to_window(so_long->mlx_connect,so_long->mlx_window, so_long->floor, x * 40, y * 40);
            if (so_long->map_ready[x][y] == '1')
                mlx_put_image_to_window(so_long->mlx_connect,so_long->mlx_window, so_long->floor, x * 40, y * 40); */
            x++;
        }
        y++;
    } 
}


/* void grafics(so_long_def *so_long)
{

    so_long->mlx_connect = mlx_init();
    so_long->mlx_window = mlx_new_window(so_long->mlx_connect,
                                        so_long->map_x * 100,
                                        so_long->map_y * 100,
                                        "so_long42");
    return ;
} */