/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 03:10:00 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/06 01:54:19 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_walls(game_def *so_long)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(so_long->map_ready[j])
        j++;
    while(so_long->map_ready[0][i])
    {
        if (so_long->map_ready[0][i] != '1' && so_long->map_ready[j][i] != '1')
            return (1); // not covered in walls (top and low line)
    }
    j = 0;
    while(so_long->map_ready[j][0])
    {
        if (so_long->map_ready[j][0] != '1' && so_long->map_ready[j][i] != '1')
            return (1); // not covered in walls (left and right walls)
    }
    return (0);
}

int check_components(game_def *so_long)
{
    int i;
    int j;
    
    j = 0;
    while(so_long->map_ready[j])
    {
        i = 0;
        while(so_long->map_ready[j][i])
            {
                if (so_long->map_ready[j][i] == 'P')
                    so_long->character++;
                if (so_long->map_ready[j][i] == 'E')
                    so_long->scape++;
                if (so_long->map_ready[j][i] == 'C')
                    so_long->coins++;
                i++;
            } 
        j++;
    }
    if (so_long->scape != 1 || so_long->character != 1 || so_long->coins < 1)
        return(1);
    return (0);
}

int check_rectangle(game_def *so_long)
{
    //printf("flag1\n");
    //printf("y = %d\tx = %d\n", so_long->map_y,  so_long->map_x);
    if (so_long->map_y >= so_long->map_x)
        return (1);
    return (0);
}

int check_all(game_def *sl)
{
    printf("0\n");
   // if (check_components(sl) != 0)
    //    return (1); // erase all, print exact mesage defining the error
    printf("1\n");
    if(check_rectangle(sl) != 0)
        return (2); // erase all, print exact mesage defining the error
    printf("2\n");
    //if(check_walls(sl) != 0)
      //  return (3); // erase all, print exact mesage defining the error
    printf("3\n");
    return (0);
}
