/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:59:38 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/27 18:40:15 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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