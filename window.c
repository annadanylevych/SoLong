/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:59:38 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/09 20:38:52 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_window) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}


int main(void)
{
	t_window	window;
	void	*img;
	t_persona perso;
	perso.x = 100;
	
	window = new_program(1920, 1080, "So Long");
	img = mlx_xpm_file_to_image(window.mlx_ptr, "image.xpm", &(window.width), &(window.height));
	
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, img, 100, 10);
	if (window.mlx_ptr == NULL || window.win_ptr == NULL)
		return(1);
	mlx_loop(window.mlx_ptr);
	return (0);
}