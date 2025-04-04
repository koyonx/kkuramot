/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutinoue <yutinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:46:14 by kkuramot          #+#    #+#             */
/*   Updated: 2025/04/03 22:48:28 by yutinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_map(int i, t_map *map, char *height_str, char *line)
{
	map->height = ft_atoi(height_str);
	free(height_str);
	if (map->height <= 0)
		return (0);
	map->empty = line[i];
	map->obstacle = line[i + 1];
	map->full = line[i + 2];
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (1);
}

int	parse_header(char *line, t_map *map)
{
	int		i;
	int		len;
	char	*height_str;
	int		j;

	len = ft_strlen(line);
	if (len < 4)
		return (0);
	i = len - 3;
	if (i <= 0)
		return (0);
	height_str = (char *)malloc(i + 1);
	if (!height_str)
		return (0);
	j = 0;
	while (j < i)
	{
		height_str[j] = line[j];
		if (line[j] < '0' || line[j++] > '9')
			return (free(height_str), 0);
	}
	height_str[j] = '\0';
	return (create_map(i, map, height_str, line));
}

int	check_line(char *line, t_map *map, int width)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != map->empty && line[i] != map->obstacle)
			return (0);
		i++;
	}
	if (width != -1 && i != width)
		return (0);
	return (i);
}

char	*read_line(int fd)
{
	char	buffer[8192 + 1];
	int		i;
	int		read_size;

	i = 0;
	while (1)
	{
		read_size = read(fd, &buffer[i], 1);
		if (read_size <= 0 || buffer[i] == '\n' || i >= 8192)
			break ;
		i++;
	}
	if (i == 0 && read_size <= 0)
		return (NULL);
	buffer[i] = '\0';
	return (ft_strdup(buffer));
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}
