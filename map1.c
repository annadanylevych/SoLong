/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:16:34 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/22 16:10:30 by adanylev         ###   ########.fr       */
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

void	check_chars(char **map, char *accept, int i)
{
	int	j;
	int	p;
	
	while (map[i])
	{
		j = 0;
		p = 0;
		while (map[i][j] && accept[p])
		{
			if (map[i][j] == accept[p])
			{
				j++;
				p = 0;
			}
			else if (map[i][j] != accept[p])
			{
				p++;
				if (!accept[p])
					map_error("Error: unacceptable characters\n", map);			
			}		
		}
		i++;				
	}
}

int	ft_strrncmp(char *s1, char*s2, int n)
{
	int	i;
	int	j;

	i = ft_strleng(s1) - 1;
	j = ft_strleng(s2) - 1;
	while (n)
	{
		if (s2[j] != s1[i])
			return (1);
		j--;
		i--;
		n--;
	}
	if (n)
		return (1);
	return (0);
}	

void	map_initial(t_map *map)
{
	int	i;

	i = 0;
	map->coin = 0;
	map->exit = 0;
	map->person = 0;
	while (map->grid[i])
		i++;
	map->size.y = i;
	map->size.x = ft_strleng(map->grid[0]);
}

void	map_check(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	map_initial(map);
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'E')
				map->exit++;
			else if (map->grid[i][j] == 'C')
				map->coin++;
			else if (map->grid[i][j] == 'P')
				map->person++;
			j++;
		}
		i++;
	}
	check_amounts(map);
}