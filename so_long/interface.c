#include "../so_long.h"

 void xpm_images(game_def *so_long)
{   
    so_long->floor = mlx_xpm_file_to_image(so_long->mlx_connect,
                                            "textures/grass.xpm", &so_long->image_width, &so_long->image_height);
    so_long->walls = mlx_xpm_file_to_image(so_long->mlx_connect,
                                            "textures/box.xpm", &so_long->image_width, &so_long->image_height);
} 

void	put_image(game_def *so_long, void *image, int x, int y)
{
	mlx_put_image_to_window
		(so_long->mlx_connect, so_long->mlx_window, image, x * 32, y * 32);
}

void	size_window_init(game_def *so_long)
{
	int	i;

	so_long->map_x = ft_strlen(so_long->map_ready[0]) * 32;
	i = 0;
	while (so_long->map_ready[i] != NULL)
		i++;
	so_long->map_y = i * 32;
}

void put_in_screen(game_def *so_long)
{
    int x;
    int y;

     y = 0;
    while (so_long->map_ready[y]) // y < so_long->map_y
    {
        x = 0;
        while(so_long->map_ready[y][x]) // x < so_long->map_x
        {
//                    printf("FLAG....\n");
                   // printf("x - %d || y - %d\n", x, y);
                   // printf("array[%d][%d] = %c\n",y,x, so_long->map_ready[y][x]);

            if (so_long->map_ready[x][y] == '0')
                put_image(so_long, so_long->walls, x, y);
            if (so_long->map_ready[x][y] == '1')
                put_image(so_long, so_long->floor, x, y);
            x++;
        }
        y++;
    } 
}
