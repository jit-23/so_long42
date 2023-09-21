#include "../so_long.h"

/* char    **check_map(char *map_raw)
{
    int fd = open(map_raw, O_RDONLY);
    char *map_line;
    char *map_cooked;
    
    map_cooked = "";
 	map_line = "";
    int flag = 0;
    ft_printf("flag1\n");
    while (map_line != NULL)
    {
        
        map_line = get_next_line(fd);
        printf("2-- %s\n", map_line);
        if (map_line == NULL || map_line[0]== '\n')
        {
            free(map_line);
            //break ;
            return (NULL);
        }
        //ft_printf("flag2\n");
        map_cooked = ft_strjoin(map_cooked, map_line);
        free(map_line);
    }
    //ft_printf("flag2\n");
    close(fd);
    if(map_line[0] == '\n') // desnecessario (lin 18)
        printf("error: invalid map");
    printf("flag4\n");
    return (ft_split(map_cooked,'\n')); // isto vai me dar 2d array de todo o mapa
}
void print_map(char **map_ready)
{
	int x = sizeof(map_ready) / sizeof(map_ready[0]);
    //int y = sizeof(map_ready[0]) / sizeof(map_ready[0][0]);
    int y = 6;
	printf("x = %d \n y = %d", x, y);
} */

 static int  x_of_map(char *line) // isto SO te da o valor do comprimento do map, nada mais
{
    int x;

    x = 0;
    while(line[x] != '\0')
        x++;
    if (line[x - 1] == '\n')
        x--;
    return (x);
} 

static int	add_line(game_def *so_long, char *line)
{
	char	**buffer; // 2d array
	int		i;

	if (!line)
		return (0);
	i = -1;
	so_long->map_y++;
	buffer = (char **)malloc(sizeof(char *) * (so_long->map_y + 1));
	buffer[so_long->map_y] = NULL;
	while (++i < so_long->map_y - 1)
		buffer[i] = so_long->map_ready[i];
	buffer[i] = line;
	if (so_long->map_ready) // se map_ready tem alguma cena, apagar tudo para meter dentro
		free(so_long->map_ready);
	so_long->map_ready = buffer;
	return (1);
} 

int read_map(game_def *so_long, char *map)
{
    char *map_line;
    so_long->fd = open(map,O_RDONLY);
    if (so_long->fd < 0)
        return (0);
     while(1)
    {
        map_line = get_next_line(so_long->fd);
        if (!add_line(so_long, map_line))
            break ;
    } 
    close(so_long->fd);
    so_long->map_x = x_of_map(so_long->map_ready[0]);
    return (1);
}