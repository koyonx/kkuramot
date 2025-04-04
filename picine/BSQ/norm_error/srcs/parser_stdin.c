/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:46:27 by kkuramot          #+#    #+#             */
/*   Updated: 2025/04/03 22:02:39 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_stdin_final_newline(int fd, char **buffer_ptr, int *size_ptr)
{
	char	*buffer;
	int		size;
	int		read_size;
	int		has_single_newline;

	buffer = NULL;
	size = 0;
	has_single_newline = 0;
	while (1)
	{
		buffer = (char *)ft_realloc(buffer, size + 8192);
		if (!buffer)
			return (0);
		read_size = read(fd, buffer + size, 8192);
		if (read_size <= 0)
			break ;
		size += read_size;
	}
	if (size == 0)
	{
		if (buffer)
			free(buffer);
		return (0);
	}
	has_single_newline = (size >= 1 && buffer[size - 1] == '\n');
	if (has_single_newline && size >= 2)
		has_single_newline = (buffer[size - 2] != '\n');
	*buffer_ptr = buffer;
	*size_ptr = size;
	return (has_single_newline);
}

char	*read_from_buffer(char **buffer_ptr, int *pos_ptr, int *size_ptr)
{
	char		*buffer;
	char		*line;
	t_support	support;

	buffer = *buffer_ptr;
	support.pos = *pos_ptr;
	support.size = *size_ptr;
	if (support.pos >= support.size)
		return (NULL);
	support.start = support.pos;
	support.i = support.pos;
	while (support.i < support.size && buffer[support.i] != '\n')
		support.i++;
	support.line_len = support.i - support.start;
	line = (char *)malloc(support.line_len + 1);
	if (!line)
		return (NULL);
	support.j = 0;
	while (support.j < support.line_len)
	{
		line[support.j] = buffer[support.start + support.j];
		support.j++;
	}
	line[support.line_len] = '\0';
	if (support.i < support.size)
		*pos_ptr = support.i + 1;
	else
		*pos_ptr = support.size;
	return (line);
}

int	init_parse_stdin(t_map *map, char **buffer, int *buffer_size)
{
	int		buffer_pos;
	char	*header;

	buffer_pos = 0;
	header = read_from_buffer(buffer, &buffer_pos, buffer_size);
	if (!header || !parse_header(header, map))
	{
		if (header)
			free(header);
		free(*buffer);
		return (0);
	}
	free(header);
	map->grid = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
	{
		free(*buffer);
		return (0);
	}
	map->width = -1;
	return (buffer_pos);
}

int	process_stdin_line(t_map *map, int *i, char **buffer, int *buffer_pos,
		int *buffer_size)
{
	char	*line;
	int		line_width;

	line = read_from_buffer(buffer, buffer_pos, buffer_size);
	if (!line)
	{
		while (*i > 0)
			free(map->grid[--(*i)]);
		free(map->grid);
		free(*buffer);
		return (0);
	}
	line_width = check_line(line, map, map->width);
	if (line_width == 0)
	{
		free(line);
		while (*i > 0)
			free(map->grid[--(*i)]);
		free(map->grid);
		return (free(*buffer), 0);
	}
	if (map->width == -1)
		map->width = line_width;
	map->grid[(*i)++] = line;
	return (1);
}

int	parse_stdin(t_map *map)
{
	t_stdin	stdin;

	if (!check_stdin_final_newline(0, &stdin.buffer, &stdin.buffer_size))
		return (0);
	stdin.buffer_pos = init_parse_stdin(map, &stdin.buffer, &stdin.buffer_size);
	if (!stdin.buffer_pos)
		return (0);
	stdin.i = 0;
	while (stdin.i < map->height)
	{
		if (!process_stdin_line(map, &stdin.i, &stdin.buffer, &stdin.buffer_pos,
				&stdin.buffer_size))
			return (0);
	}
	map->grid[stdin.i] = NULL;
	stdin.line = read_from_buffer(&stdin.buffer, &stdin.buffer_pos,
			&stdin.buffer_size);
	if (stdin.line)
	{
		free(stdin.line);
		while (stdin.i > 0)
			free(map->grid[--stdin.i]);
		return (free(map->grid), free(stdin.buffer), 0);
	}
	return (free(stdin.buffer), 1);
}
