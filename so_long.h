/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:27:19 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/21 12:51:09 by adanylev         ###   ########.fr       */
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
}				t_long;



t_window new_program(int w, int h, char *str);
char	**map_parsing(int argc, char **argv);
char	**map_parsing1(int fd, char *line, char *tmp, char **map);
char	**get_map(char *tmp);
void	check_walls1(int j, char **map);
void	check_walls(char **map);
int		ft_strrncmp(char *s1, char*s2, int n);
void	map_error(char *msg, char **map);
void	check_chars(char **map);

#endif