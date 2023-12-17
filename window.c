/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:59:38 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/17 19:04:48 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_window) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

void start(t_long *game)
{
	void	*img;
	
	game->win = new_program(1920, 1080, "So Long");
	img = mlx_xpm_file_to_image(game->win.mlx_ptr, "background.xpm", &game->win.width, &game->win.height);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, img, 0, 0);
	// if (game->win.mlx_ptr == NULL || game->win.win_ptr == NULL)
	// 	return(1);
	mlx_loop(game->win.mlx_ptr);
}

int	main(int argc, char **argv)
{
//	t_long	game;
	char	**map;
	int	i;
	
	i = 0;
	map = map_parsing(argc, argv);
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	return (0);
}

int	ft_strrncmp(char *s1, char*s2, int n)
{
	int	i;
	int	j;

	i = ft_strleng(s1) - 1;
	j = ft_strleng(s2) - 1;
	while (n)
	{
		if (s2[j] != s1[i])
			return (1);
		j--;
		i--;
		n--;
	}
	if (n)
		return (1);
	return (0);
}	



