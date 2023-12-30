/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:27:19 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/30 16:15:32 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct s_sprites
{
	void		*backround;
	void		*duck;
	void		*exit;
	void		*coins;
	void		*ending;
	void		*wall;
	void		*duck_left;
}				t_sprites;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_map
{
	char		**grid;
	char		**fill;
	int			person;
	int			coin;
	int			collected;
	int			exit;
	int			pared;
	t_point		*wall;
	t_point		pers;
	t_point		*coins;
	t_point		salida;
	t_point		size;
}				t_map;

typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_window;

typedef struct s_long
{
	t_window	win;
	t_map		map;
	t_sprites	imgs;
	int			moves;
	int			won;
}				t_long;

t_window		new_program(int w, int h, char *str);
char			**map_parsing(int argc, char **argv);
char			**map_parsing1(int fd, char *line, char *tmp, char **map);
char			**get_map(char *tmp);
void			check_walls1(int j, char **map);
void			check_walls(char **map);
int				ft_strrncmp(char *s1, char *s2, int n);
void			map_error(char *msg, char **map);
void			check_chars(char **map, char *accept, int i);
void			map_check(t_map *map);
void			check_amounts(t_map *map);
void			filled_map(t_map *map);
void			flood_fill(char **filled, t_point size, t_point begin);
void			coords_init(t_point *this, int i, int j);
void			get_coords(t_map *map);
char			**filling_map(t_map *map);
void			big_error(t_map *map);
int				check_if_empty(int i, int j, t_map *map);
void			check_path(t_map *map);
void			fill_blue(t_long *game);
void			start(t_long *game);
void			fill_sprites(t_long *game);
void			put_sprites(t_long *game);
void			walls(t_long *game);
void			coins(t_long *game);
int				function(t_long *game);
int				hook_up(int event, t_long *game);
void			go_up(t_long *game);
void			win(t_long *game);
void			go_down(t_long *game);
void			go_right(t_long *game);
void			go_left(t_long *game);
void			got_baguette(t_long *game);

#endif
