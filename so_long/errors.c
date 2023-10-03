/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:58:14 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/09/26 17:17:32 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_rectangle(game_def *so_long)
{
    printf("y = %d\tx = %d\n", so_long->map_y,  so_long->map_x);
    if (so_long->map_y >= so_long->map_x)
        return (1);
    return (0);
}
