/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:59:38 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/16 21:41:31 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_window) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

void start(char **argv)
{
	t_long	game;
	void	*img;
	
	game.window = new_program(1920, 1080, "So Long");
	img = mlx_xpm_file_to_image(game.win->mlx_ptr, "background.xpm", &(game.win->width), &(game.win->height));
	mlx_put_image_to_window(game.win->mlx_ptr, game.win->win_ptr, img, 0, 0);
	if (game.win->mlx_ptr == NULL || game.win->win_ptr == NULL)
		return(1);
	mlx_loop(game.win->mlx_ptr);
	return (0);
}
