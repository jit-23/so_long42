#ifndef SO_LONG_H
#define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct game_definitions
{
    int		fd;
    int		map_x;
    int		map_y;

    char	**map_ready;
    
    void	*mlx_window;
    void	*mlx_connect;

    void    *floor;
	void    *walls;

} game_def;

int     read_map(game_def *so_long, char *map);
//void  grafics(game_def *so_long);
void    xpm_images(game_def *so_long);
void        put_in_screen(game_def *so_long);
//void    print_map(char **map_ready);
//char    **check_map(char *map_raw);

#endif