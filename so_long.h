#ifndef SO_LONG_H
#define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct game_definitions
{
    int		fd;
    int		map_x;
    int		map_y;
    int		map_width;
    int		map_height;
    
    int     image_width;
    int     image_height;

    char	**map_ready;
    
    void	*mlx_window;
    void	*mlx_connect;

    
    void    *floor;
	void    *walls;
    void    *exit;



} game_def;



int     read_map(game_def *so_long, char *map);
void    xpm_images(game_def *so_long);
void        put_in_screen(game_def *so_long);
int command_input(int key_command, game_def *so_long);
int check_rectangle(game_def *so_long);
void exit_window(game_def *so_long);
void	size_window_init(game_def *so_long);
void	put_img(game_def *so_long, void *image, int x, int y);


#endif