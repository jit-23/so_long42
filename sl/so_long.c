/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:34:40 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/14 20:04:11 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	memory_alloc(t_game_def *sl)
{
	sl->map_ready = ft_calloc(sl->map_y + 1, sizeof(char *));
	if (!sl->map_ready)
		exit_msg(sl, "Can't allocate mem.\n");
	sl->xpm = ft_calloc(5, sizeof(t_image));
	if (!sl->xpm)
		exit_msg(sl, "Can't allocate mem.\n");
}

void	game_init(t_game_def *sl, char *file_name)
{
	ft_bzero(sl, sizeof(t_game_def));
	sl->file = file_name;
	map_size(sl);
	memory_alloc(sl);
	read_map(sl);
	line_sizes(sl);
	check_all(sl);
	check_path(sl);
	sl->mlx_con = mlx_init();
	if (!sl->mlx_con)
		exit_msg(sl, "Can't init connection.\n");
	sl->mlx_win = mlx_new_window(sl->mlx_con,
			sl->map_x * PIXEL, sl->map_y * PIXEL, "so long");
	if (!sl->mlx_win)
		exit_msg(sl, "Can't init win.\n");
	xpm_allocation(sl);
	put_in_screen(sl);
	mlx_key_hook(sl->mlx_win, command_input, sl);
	mlx_hook(sl->mlx_win, 17, 0, (void *)close_w, sl);
	mlx_loop(sl->mlx_con);
}

int	main(int argc, char *argv[])
{
	t_game_def	sl;
	char		*file;
	int			i;

	if (argc != 2)
	{
		printf("Wrong number of arguments.\n");
		return (1);
	}
	file = argv[1];
	i = ft_strlen(file) - 1;
	if (file[i - 3] == '.' && file[i - 2] == 'b'
		&& file[i - 1] == 'e' && file[i] == 'r')
		game_init(&sl, argv[1]);
	else
		ft_printf("Wrong type of map file.\n");
	return (0);
}
