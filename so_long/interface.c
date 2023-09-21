#include "../so_long.h"

void xpm_images(game_def *so_long)
{
    int i;
    int j;
    // mlx_put_image_to_window(so_long->mlx_connect,
    //                                         so_long->mlx_window,
    //                                         so_long->floor,
    //                                         so_long->map_x * 100,
    //                                         so_long->map_y * 100);
    
    so_long->floor = mlx_xpm_file_to_image(so_long->mlx_connect,
                                            "grass.xpm", &i, &j);
    
}
void put_in_screen(game_def *so_long)
{
    int x;
    int y;

     x = 0;
    while (x < so_long->map_x)
    {
        y = 0;
        while(so_long->map_ready[x][y])
        {
                    printf("FLAG....\n");
                    printf("x - %d || y - %d\n", x, y);

            if (so_long->map_ready[x][y] == '1' || so_long->map_ready[x][y] == '0')
               mlx_put_image_to_window(so_long->mlx_connect,
					so_long->mlx_window, so_long->floor, x * 40, y * 40);
                    printf("ssss\n");
            y++;
        }
        x++;
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