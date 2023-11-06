#ifndef SO_LONG_H
#define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
#include <stdio.h>
#define PIXEL 32

typedef struct s_image
{
	void	*img;
	int		x;
	int		y;
}			t_image;


typedef struct game_definitions
{
    t_image *xpm;
	int		fd;
    int		map_x;
    int		map_y;
    int		map_width;
    int		map_height;

    char	**map_ready;
    
    void	*mlx_win;
    void	*mlx_con;

    
    void    *floor;
	void    *walls;
    void    *exit;
    
    int coins;
    int character;
    int scape;
    
    int player_steps;
    int player_x; 
    int player_y;
}					game_def;


void map_size(game_def *so_long, char *map_name);
int read_map(game_def *so_long, char *map);
void xpm_allocation(game_def *sl);
void put_in_screen(game_def *sl);
void exit_window(game_def *sl);
int command_input(int key_command, game_def *sl);
int check_all(game_def *so_long);
int check_rectangle(game_def *so_long);
int check_components(game_def *so_long);
int check_walls(game_def *so_long);
void error_map(game_def *sl);
int keys_AD(int key_command,game_def *sl);
int keys_WS(int key_command,game_def *sl);
int    player_move(game_def *sl, int j, int i);
#endif
