/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:27:19 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/22 16:25:16 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "lib/libft.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_map
{
	char	**grid;
	char	**fill;
	int		person;
	int		coin;
	int		exit;
	t_point	pers;
	t_point	*coins;
	t_point	salida;
	t_point	size;
}			t_map;


typedef	struct	s_window
{	
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}			t_window;

typedef	struct	s_long
{
	t_window	win;
	t_map		map;
}				t_long;



t_window new_program(int w, int h, char *str);
char	**map_parsing(int argc, char **argv);
char	**map_parsing1(int fd, char *line, char *tmp, char **map);
char	**get_map(char *tmp);
void	check_walls1(int j, char **map);
void	check_walls(char **map);
int		ft_strrncmp(char *s1, char*s2, int n);
void	map_error(char *msg, char **map);
void	check_chars(char **map, char *accept, int i);
void	map_check(t_map	*map);
void	check_amounts(t_map *map);
void	filled_map(t_map *map);
void	flood_fill(char **filled, t_point size, t_point begin);

#endif