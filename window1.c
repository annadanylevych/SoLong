/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:51:43 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/28 19:05:49 by adanylev         ###   ########.fr       */
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
	(void)game;
	exit(1);
	return (1);
}

int	hook_up(int event, t_long *game)
{
	if (event == 13)
		go_up(game);
	else if (event == 1)
		go_down(game);
	else if (event == 2)
		go_right(game);
	else if (event == 0)
		go_left(game);
	else if (event == 53)
		function(game);
	ft_printf("MOVES: %d\n", game->moves);
	return (0);
}

void	got_baguette(t_long *game)
{
	int	i;

	i = 0;
	while (i < game->map.coin)
	{
		if (game->map.pers.x == game->map.coins[i].x
			&& game->map.pers.y == game->map.coins[i].y)
			game->map.coin--;
		i++;
	}
}
