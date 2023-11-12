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
	char		*file;
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
	int player_y_bf;
	int player_x_bf;
}					game_def;



void map_size(game_def *sl);
int read_map(game_def *sl);
void xpm_allocation(game_def *sl);
void put_in_screen(game_def *sl);
void exit_window(game_def *sl);
int command_input(int key_command, game_def *sl);
void check_all(game_def *sl);
int check_rectangle(game_def *sl);
int check_components(game_def *sl);
int check_walls(game_def *sl);
void error_map(game_def *sl);
int keys_ad(int key_command,game_def *sl);
int keys_ws(int key_command,game_def *sl);
int    player_move(game_def *sl, int j, int i);
int flood_fill(game_def *sl,char  **map_copy, int x,int y);
int check_path(game_def *sl);
void line_sizes(game_def *sl);

#endif
