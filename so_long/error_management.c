/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 02:33:45 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/11/13 03:02:46 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_msg(game_def *sl, char *msg)
{
	delete_mem(sl);
	ft_printf("%s", msg);
	exit (0);
}

void delete_mem(game_def *sl)
{
	
}