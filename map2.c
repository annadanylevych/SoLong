/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:01:04 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/22 19:45:58 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_coords(t_map *map)
{
	int	i;
	int	j;
	int p;

	i = 0;
	p = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			printf("map is: %c\n", map->grid[i][j]);
			if (map->grid[i][j] == 'E')
				coords_init(&map->salida, i, j);
			else if (map->grid[i][j] == 'C')
				coords_init(&map->coins[p++], i, j);
			else if (map->grid[i][j] == 'P')
				coords_init(&map->pers, i, j);
			j++;
		}
		i++;
	}
}

void	check_amounts(t_map *map)
{
	if (map->exit != 1)
		map_error("Error: invalid map, we need 1 exit; not more, not less.\n",
			map->grid);
	else if (map->person != 1)
		map_error("Error: invalid map, we need 1 player; not more, not less.\n",
			map->grid);
	else if (map->coin < 1)
		map_error("Error: invalid map, we need coin(s).\n", map->grid);
}

void	filled_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->fill = filling_map(map);
	while (map->fill[i])
	{
		j = 0;
		while (map->fill[i][j])
		{
			if (map->fill[i][j] == 'C' || map->fill[i][j] == 'P'
				|| map->fill[i][j] == 'E')
				map->fill[i][j] = '0';
			j++;
		}
		i++;
	}
	get_coords(map);
	flood_fill(map->fill, map->size, map->pers);
}

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **filled, t_point size, t_point begin)
{
	fill(filled, size, begin, filled[begin.x][begin.y]);
}
