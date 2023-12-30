/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:51:43 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/30 16:30:58 by adanylev         ###   ########.fr       */
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
				mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
					game->imgs.wall, x * 64, y * 64);
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
				mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
					game->imgs.coins, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

int	function(t_long *game)
{
	int	i;

	i = 0;
	while (game->map.grid[i])
	{
		free(game->map.grid[i]);
		game->map.grid[i] = NULL;
		i++;
	}
	i = 0;
	while (game->map.fill[i])
	{
		free(game->map.fill[i]);
		game->map.fill[i] = NULL;
		i++;
	}
	free(game->map.coins);
	game->map.coins = NULL;
	exit(1);
	return (1);
}

int	hook_up(int event, t_long *game)
{
	if (event == 13 && !game->won)
		go_up(game);
	else if (event == 1 && !game->won)
		go_down(game);
	else if (event == 2 && !game->won)
		go_right(game);
	else if (event == 0 && !game->won)
		go_left(game);
	else if (event == 53)
		function(game);
	return (0);
}

void	got_baguette(t_long *game)
{
	int	i;

	i = 0;
	while (game->map.coin > i)
	{
		if (game->map.pers.x == game->map.coins[i].x
			&& game->map.pers.y == game->map.coins[i].y)
		{
			game->map.coins[i].x = 0;
			game->map.coins[i].y = 0;
			game->map.collected++;
		}
		i++;
	}
}
