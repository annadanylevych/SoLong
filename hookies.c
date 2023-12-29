/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:01:49 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/29 15:16:34 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_long *game)
{
	if (game->map.pers.x == game->map.salida.x && game->map.pers.y
		- 1 == game->map.salida.y && game->map.coin > 0)
		return ;
	else if (game->map.grid[game->map.pers.y - 1][game->map.pers.x] != '1')
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->imgs.backround, game->map.pers.x * 64, game->map.pers.y * 64);
		game->map.pers.y--;
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->imgs.duck, game->map.pers.x * 64, game->map.pers.y * 64);
		game->moves++;
		ft_printf("MOVES: %d\n", game->moves);
		got_baguette(game);
		win(game);
	}
}

void	go_down(t_long *game)
{
	if (game->map.pers.x == game->map.salida.x && game->map.pers.y
		+ 1 == game->map.salida.y && game->map.coin > 0)
		return ;
	else if (game->map.grid[game->map.pers.y + 1][game->map.pers.x] != '1')
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->imgs.backround, game->map.pers.x * 64, game->map.pers.y * 64);
		game->map.pers.y++;
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->imgs.duck, game->map.pers.x * 64, game->map.pers.y * 64);
		game->moves++;
		ft_printf("MOVES: %d\n", game->moves);
		got_baguette(game);
		win(game);
	}
}

void	go_right(t_long *game)
{
	if (game->map.pers.x + 1 == game->map.salida.x
		&& game->map.pers.y == game->map.salida.y && game->map.coin > 0)
		return ;
	else if (game->map.grid[game->map.pers.y][game->map.pers.x + 1] != '1')
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->imgs.backround, game->map.pers.x * 64, game->map.pers.y * 64);
		game->map.pers.x++;
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->imgs.duck, game->map.pers.x * 64, game->map.pers.y * 64);
		game->moves++;
		ft_printf("MOVES: %d\n", game->moves);
		got_baguette(game);
		win(game);
	}
}

void	go_left(t_long *game)
{
	if (game->map.pers.x - 1 == game->map.salida.x
		&& game->map.pers.y == game->map.salida.y && game->map.coin > 0)
		return ;
	else if (game->map.grid[game->map.pers.y][game->map.pers.x - 1] != '1')
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->imgs.backround, game->map.pers.x * 64, game->map.pers.y * 64);
		game->map.pers.x--;
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->imgs.duck_left, game->map.pers.x * 64, game->map.pers.y * 64);
		game->moves++;
		ft_printf("MOVES: %d\n", game->moves);
		got_baguette(game);
		win(game);
	}
}

void	win(t_long *game)
{
	int	x;
	int	y;

	y = 0;
	if (game->map.pers.x == game->map.salida.x
		&& game->map.pers.y == game->map.salida.y && game->map.coin == 0)
	{
		while (y <= game->map.size.y * 64)
		{
			x = 0;
			while (x <= game->map.size.x * 64)
			{
				mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
					game->imgs.ending, y, x);
				x = x + 64;
			}
			y = y + 64;
		}
		game->won = 1;
	}
}
