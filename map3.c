/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:29:05 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/23 12:26:16 by adanylev         ###   ########.fr       */
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