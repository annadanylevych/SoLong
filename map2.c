/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:01:04 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/22 16:26:25 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_amounts(t_map *map)
{
	if (map->exit != 1)
		map_error("Error: invalid map, we need 1 exit; not more, not less.\n", map->grid);
	else if (map->person != 1)
		map_error("Error: invalid map, we need 1 player; not more, not less.\n", map->grid);
	else if (map->coin < 1)
		map_error("Error: invalid map, we need coin(s).\n", map->grid);
}

void	filled_map(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	map->fill = map->grid;
	while (map->fill[i])
	{
		j = 0;
		while (map->fill[i][j])
		{
			if (map->fill[i][j] == 'C' || map->fill[i][j] == 'P' || map->fill[i][j] == 'E')
				map->fill[i][j] = '0';
			j++;
		}
		i++;
	}
	map->pers.x = 1;
	map->pers.y = 1;
	flood_fill(map->fill, map->size, map->pers)	;
}

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **filled, t_point size, t_point begin)
{
	fill(filled, size, begin, filled[begin.y][begin.x]);
}