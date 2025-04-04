/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutinoue <yutinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:46:24 by kkuramot          #+#    #+#             */
/*   Updated: 2025/04/03 20:11:23 by yutinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_final_newline(int fd)
{
	char	last_char;
	char	prev_char;
	int		file_size;
	int		read_result;

	if (ft_lseek(fd, 0, SEEK_CUR) < 0)
		return (0);
	file_size = ft_lseek(fd, 0, SEEK_END);
	if (file_size <= 0)
		return (0);
	if (ft_lseek(fd, file_size - 1, SEEK_SET) < 0)
		return (0);
	read_result = read(fd, &last_char, 1);
	if (read_result != 1 || last_char != '\n')
		return (0);
	if (file_size >= 2)
	{
		if (ft_lseek(fd, file_size - 2, SEEK_SET) < 0)
			return (0);
		read_result = read(fd, &prev_char, 1);
		if (read_result == 1 && prev_char == '\n')
			return (0);
	}
	return (ft_lseek(fd, ft_lseek(fd, 0, SEEK_CUR), SEEK_SET), 1);
}

int	init_parse_file(char *filename, t_map *map, int *fd, char **header)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (0);
	if (!check_final_newline(*fd))
	{
		close(*fd);
		return (0);
	}
	ft_lseek(*fd, 0, SEEK_SET);
	*header = read_line(*fd);
	if (!*header || !parse_header(*header, map))
	{
		if (*header)
			free(*header);
		close(*fd);
		return (0);
	}
	free(*header);
	return (1);
}

int	allocate_grid(t_map *map, int fd)
{
	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
	{
		close(fd);
		return (0);
	}
	map->width = -1;
	return (1);
}

int	process_line(t_map *map, int *i, int fd)
{
	char	*line;
	int		line_width;

	line = read_line(fd);
	if (!line)
	{
		while (*i > 0)
			free(map->grid[--(*i)]);
		free(map->grid);
		close(fd);
		return (0);
	}
	line_width = check_line(line, map, map->width);
	if (line_width == 0)
	{
		free(line);
		while (*i > 0)
			free(map->grid[--(*i)]);
		free(map->grid);
		close(fd);
		return (0);
	}
	if (map->width == -1)
		map->width = line_width;
	return (map->grid[(*i)++] = line, 1);
}

int	parse_file(char *filename, t_map *map)
{
	int		fd;
	char	*header;
	char	*line;
	int		i;

	if (!init_parse_file(filename, map, &fd, &header))
		return (0);
	if (!allocate_grid(map, fd))
		return (0);
	i = 0;
	while (i < map->height)
	{
		if (!process_line(map, &i, fd))
			return (0);
	}
	map->grid[i] = NULL;
	line = read_line(fd);
	if (line)
	{
		free(line);
		while (i > 0)
			free(map->grid[--i]);
		return (free(map->grid), close(fd), 0);
	}
	return (close(fd), 1);
}
