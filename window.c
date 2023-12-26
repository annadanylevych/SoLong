/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:39:09 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/26 18:17:54 by adanylev         ###   ########.fr       */
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
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->imgs.duck, 0, 0);
	mlx_loop(game->win.mlx_ptr);
}

void	fill_blue(t_long *game)
{
	int		x;
	int		y;
	int	size;
	
	size = 64;
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
	int	i;

	size = 100;
	i = 0;
	game->imgs.duck = mlx_xpm_file_to_image(game->win.mlx_ptr, "duck.xpm", &size, &size);
	game->imgs.exit = mlx_xpm_file_to_image(game->win.mlx_ptr, "green_duck.xpm", &size, &size);
	game->imgs.ending = mlx_xpm_file_to_image(game->win.mlx_ptr, "final.xpm", &size, &size);
	game->imgs.coins = malloc(sizeof(char *) * game->map.coin);
	if (!game->imgs.coins)
		big_error(&game->map);
	while (i < game->map.coin)
	{
		game->imgs.coins[i] = mlx_xpm_file_to_image(game->win.mlx_ptr, "baguette.xpm.xpm", &size, &size);
		i++;
	}
	game->imgs.coins[i] = NULL;
}