/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:51:43 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/27 18:42:22 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walls(t_long *game)
{
	int	y;
	int	x;
	
	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == '1')
			{
				mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->imgs.wall, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	coins(t_long *game)
{
	int	y;
	int	x;
	
	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'C')
			{
				mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->imgs.coins, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

int	function(t_long *game)
{
	(void)game;
	exit (1);
	return (1);
}

int	function1(int event, t_long *game)
{
	(void)game;
	ft_printf("%d\n", event);
	return (0);
}


