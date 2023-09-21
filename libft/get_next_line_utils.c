/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:45:26 by fde-jesu          #+#    #+#             */
/*   Updated: 2023/09/19 15:37:04 by fde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strchr(const char *str, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			return (&str[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

// char	*ft_gnl_strjoin(char *start, char *buff) 

// {
// 	char	*ptr;

// 	if (!start)
// 	{
// 		start = (char *)malloc(1 * sizeof(char));
// 		start[0] = '\0';
// 	}
// 	if (!buff)
// 		return (NULL);
// 	ptr = (char *)malloc(1 + ft_strlen(start) + ft_strlen(buff) * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	ptr = ft_join(ptr, start, buff);
// 	free(start);
// 	return (ptr);
// }

// char	*ft_join(char *dest, char *s1, char *s2)
// {
	// size_t	i;
	// size_t	j;
// 
	// i = 0;
	// while (s1 && s1[i])
	// {
		// dest[i] = s1[i];
		// i++;
	// }
	// j = 0;
	// while (s2 && s2[j])
	// {
		// dest[i + j] = s2[j];
		// j++;
	// }
	// dest[i + j] = '\0';
	// return (dest);
// }


char	*ft_gnl_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_gnl_strjoin(char *start, char *buff)
{
	char	*new_fd_str;

	if (!start)
	{
		start = (char *)malloc(1 * sizeof(char));
		start[0] = '\0';
	}
	if (!buff)
		return (NULL);
	new_fd_str = (char *)malloc(1 + (ft_strlen(start) 
				+ ft_strlen(buff)) * sizeof(char));
	if (!new_fd_str)
		return (NULL);
	new_fd_str = ft_join(new_fd_str, start, buff);
	free(start);
	return (new_fd_str);
}

 char	*ft_join(char *new_fd_str, char *start, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (start && start[i])
	{
		new_fd_str[i] = start[i];
		i++;
	}
	while (buff && buff[j])
	{
		new_fd_str[i + j] = buff[j];
		j++;
	}
	new_fd_str[i + j] = '\0';
	return (new_fd_str);
}