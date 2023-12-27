/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:39:09 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/27 18:46:30 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_window){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str)});
}

void	start(t_long *game)
{	
	game->win = new_program(game->map.size.x * 64, game->map.size.y * 64, "So Long");
	fill_blue(game);
	fill_sprites(game);
	put_sprites(game);
	mlx_key_hook(game->win.win_ptr, function1, game);
	mlx_hook(game->win.win_ptr, 17, 0, function, &game);
	mlx_loop(game->win.mlx_ptr);
}

void	fill_blue(t_long *game)
{
	int		x;
	int		y;
	
	y = 0;
	game->imgs.backround = mlx_xpm_file_to_image(game->win.mlx_ptr, "background.xpm",
			&game->map.size.x, &game->map.size.y);
	while (y <= game->map.size.y * 64)
	{
		x = 0;
		while (x <= game->map.size.x * 64)
		{
			mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->imgs.backround, y, x);
			x = x + 64;
		}
		y = y + 64;
	}
	if (game->win.mlx_ptr == NULL || game->win.win_ptr == NULL)
		return ;
}

void	fill_sprites(t_long *game)
{
	int	size;

	size = 1;
	game->imgs.duck = mlx_xpm_file_to_image(game->win.mlx_ptr, "duck.xpm", &size, &size);
	game->imgs.exit = mlx_xpm_file_to_image(game->win.mlx_ptr, "green_duck.xpm", &size, &size);
	game->imgs.ending = mlx_xpm_file_to_image(game->win.mlx_ptr, "final.xpm", &size, &size);
	game->imgs.wall = mlx_xpm_file_to_image(game->win.mlx_ptr, "green_leaf.xpm", &size, &size);
	game->imgs.coins = mlx_xpm_file_to_image(game->win.mlx_ptr, "baguette.xpm", &size, &size);
}

void	put_sprites(t_long *game)
{
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->imgs.duck, game->map.pers.x * 64, game->map.pers.y * 64);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->imgs.exit, game->map.salida.x * 64, game->map.salida.y * 64);
	walls (game);
	coins (game);
}
