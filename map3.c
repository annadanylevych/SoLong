/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:29:05 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/23 16:46:20 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coords_init(t_point *this, int i, int j)
{
	this->x = j;
	this->y = i;
}

char	**filling_map(t_map *map)
{
	char	**newmap;
	int	i;
	int	j;

	i = 0;
	newmap = malloc(sizeof(char *) * (map->size.y + 1));
	while (map->grid[i])
	{
		j = 0;
		newmap[i] = malloc(sizeof(char) * map->size.x);
		while (map->grid[i][j])
		{
			newmap[i][j] = map->grid[i][j];
			j++;
		}
		i++;
	}
	newmap[i] = NULL;
	return (newmap);
}

void	check_path(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map->fill[i])
	{
		j = 0;
		while (map->fill[i][j])
		{
			if (map->fill[i][j] == '0')
			{
				if (check_if_empty(i, j, map) == );
			}
		}
	}
}

int	check_if_empty(int i, int j, t_map *map)
{
	while (map->fill[i][j] == 0)
	{
		
	}
}

void	big_error(t_map *map)
{
	int	i;

	i = 0;
	while (map->fill[i])
	{
		free(map->fill[i]);
		map->fill[i] = NULL;
		i++;
	}
	free(map->coins);
	map_error("Error: Imvalid map.\n", map->grid);
}