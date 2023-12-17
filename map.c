/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:06:46 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/17 16:35:57 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *msg, char **map)
{
	int	i;
	
	write(2, msg, ft_strleng(msg));
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	exit (1);
}

char	**map_parsing(int argc, char **argv)
{
	char	*line;
	char	*tmp;
	char	**map;
	int		fd;

	if (argc != 2)
	{
		write(2, "Invalid number of argumemnts\n", 30);
		exit (1);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(line, tmp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map = get_map(tmp);
	return (map);
}

char	**get_map(char *tmp)
{
	char	**map;
	int		i;
	
	map = ft_split(tmp, '\n');
	i = 0;
	while (map[1][i])
	{
		if (map[1][i] != '1')
			map_error("Error: no walls around\n", map);
		i++;
	}
	i = 0;
	while (map[i][1])
	{
		if (map[i][1] != '1')
			map_error("Error: no walls around\n", map);
		i++;
	}
	return (map);
	//check_map(map);
}

// void	check_map(char **map)
// {
// 	int	i;
// 	int	e;
// 	int p;
// 	int	j;
	
// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 	}
// }


