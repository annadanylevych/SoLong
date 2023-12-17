/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:06:46 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/17 19:30:41 by adanylev         ###   ########.fr       */
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

	tmp = ft_calloc(1, sizeof(char));
	if (!tmp)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || ft_strrncmp(argv[1], ".ber", 4) || fd < 0)
	{
		write(2, "Error: incorrect input\n", 24);
		exit (1);
	}
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
	
	printf("%s\n", tmp);
	map = ft_split(tmp, '\n');
	i = 0;
	while (map[0][i] && map[0][i] != '\n')
	{
		ft_printf("here is i: %c\n", map[0][i]);
		if (map[0][i] != '1')
			map_error("1Error: no walls around\n", map);
		i++;
	}
	i = 0;
	while (map[i] && map[i][0])
	{
		ft_printf("here2 is i: %c\n", map[i][0]);
		if (map[i][0] != '1')
			map_error("2Error: no walls around\n", map);
		i++;
	}
	//ft_printf("after while\n");
	check_map(map);
	return (map);
}

void	check_map(char **map)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	//printf("helo\n");
	len = ft_strleng(map[0]);
	printf("helo2\n");
	while (map[i])
	{
		if (len != ft_strleng(map[i]))
			map_error("3Error: map is not even\n", map);
		i++;
	}
	len--;
	j = 0;
	printf("helo3\n");
	while (map[j] && map[j][len])
	{
		if (map[j][len] != '1')
			map_error("4Error: no walls around\n", map);
		j++;
	}
	j--;
	printf("helo4\n");
	check_map1(j, map);
}

void	check_map1(int j, char **map)
{
	int	i;

	i = 0;
	while (map[j][i])
	{
		if (map[j][i] != '1')
			map_error("Error: no walls around\n", map);
		i++;
	}
}


