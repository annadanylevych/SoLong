/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:59:38 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/26 15:33:37 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_window){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

void	start(t_long *game)
{
	void	*img;
	int		x;
	int		y;
	
	y = 0;
	game->win = new_program(game->map.size.x * 64, game->map.size.y * 64, "So Long");
	img = mlx_xpm_file_to_image(game->win.mlx_ptr, "background.xpm",
			&game->map.size.x, &game->map.size.y);
	while (y <= game->map.size.y * 64)
	{
		x = 0;
		while (x <= game->map.size.x * 64)
		{
			mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, img, y, x);
			x = x + 64;
		}
		y = y + 64;
	}
	if (game->win.mlx_ptr == NULL || game->win.win_ptr == NULL)
		return ;
	mlx_loop(game->win.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_long	game;
	int		i;

	i = 0;
	game.map.grid = map_parsing(argc, argv);
	map_check(&game.map);
	filled_map(&game.map);
	start(&game);
	return (0);
}
