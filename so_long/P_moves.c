/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:31:48 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/06 04:10:54 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int    player_move(game_def *sl, int j, int i)
{
    if(sl->map_ready[j][i] == '0')
    {
        sl->map_ready[j][i] = 'P';
        //printf("P ======= %c\n",sl->map_ready[j][i]);
        sl->player_x = i;
        sl->player_y = j;
        sl->player_steps++;
    }
    if(sl->map_ready[j][i] == 'C')
    {
        sl->map_ready[j][i] = 'P';
        sl->player_x = i;
        sl->player_y = j;
        sl->coins--;
        sl->player_steps++;
    }
    if (sl->map_ready[j][i] == 'E')
    {
        if (sl->coins != 0)
            return (0);
        printf("You won!!!\n");
        exit_window(sl);
    }
    put_in_screen(sl);
    return (1);
}

int keys_WS(int key_command,game_def *sl)
{
    int i;
    int j;
    i = sl->player_x;
    j = sl->player_y;
    if (key_command == 65362)
    {
        j--;
     //   printf("W\t");
        if (sl->map_ready[j][i] == '1')
            return (0);
        if(!player_move(sl, j, i))
            return (0);
    }
    if (key_command == 65364)
    {
        j++;
       // printf("S\t");
        if(sl->map_ready[j][i] == '1')
            return (0);
        if(!player_move(sl, j, i))
            return (0);
    }
    return (1);
}

int keys_AD(int key_command,game_def *sl)
{
    int i;
    int j;
    
    i = sl->player_x;
    j = sl->player_y;
    if (key_command == 65363)
    {    
       // printf("D\t");
        i++;
        if (sl->map_ready[j][i] == '1')
            return (0);
        if(!player_move(sl, j, i))
            return (0);
    }
    if (key_command == 65361)
    {
        //printf("A\t");
        i--;
        if(sl->map_ready[j][i] == '1')
            return (0);
        if(!player_move(sl, j, i))
            return (0);
    }
    return (1);
}