/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:16:34 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/21 12:55:51 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *msg, char **map)
{
	int	i;
	
	write(2, msg, ft_strleng(msg));
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	exit (1);
}

void	check_chars(char **map)
{
	int	i;
	int	j;
	int	p;
	char	*accept;
	
	accept = "10PEC";
	i = 0;
	while (map[i])
	{
		j = 0;
		p = 0;
		while (map[i][j++] && accept[p])
		{
			if (map[i][j++] != accept[p])
			{
				p++;
				if (!accept[p])
					map_error("Error: unacceptable characters\n", map);			
			}		
		}
		i++;				
	}
}