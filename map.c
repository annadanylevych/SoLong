/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:06:46 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/21 12:51:00 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_parsing(int argc, char **argv)
{
	char	*line;
	char	*tmp;
	char	**map;
	int		fd;

	map = NULL;
	line = NULL;
	tmp = ft_calloc(1, sizeof(char));
	if (!tmp)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4) || fd < 0)
	{
		write(2, "Error: incorrect input\n", 24);
		free(tmp);
		exit (1);
	}
	map = map_parsing1(fd, line, tmp, map);
	return (map);
}

char	**map_parsing1(int fd, char *line, char *tmp, char **map)
{
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(tmp, line);
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
	while (map[0][i] && map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			map_error("Error: no walls around\n", map);
		i++;
	}
	i = 0;
	while (map[i] && map[i][0])
	{
		if (map[i][0] != '1')
			map_error("Error: no walls around\n", map);
		i++;
	}
	check_walls(map);
	return (map);
}

void	check_walls(char **map)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	len = ft_strleng(map[0]);
	while (map[i])
	{
		if (len != ft_strleng(map[i]))
			map_error("Error: map is not even\n", map);
		i++;
	}
	len--;
	j = 0;
	while (map[j] && map[j][len])
	{
		if (map[j][len] != '1')
			map_error("Error: no walls around\n", map);
		j++;
	}
	j--;
	check_walls1(j, map);
}

void	check_walls1(int j, char **map)
{
	int	i;

	i = 0;
	while (map[j][i])
	{
		if (map[j][i] != '1')
			map_error("Error: no walls around\n", map);
		i++;
	}
	check_chars(map);
}