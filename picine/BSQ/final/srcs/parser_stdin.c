/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutinoue <yutinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:46:27 by kkuramot          #+#    #+#             */
/*   Updated: 2025/04/03 23:22:09 by yutinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_stdin_final_newline(int fd, char **buffer_ptr, int *size_ptr)
{
	char	*buffer;
	int		size;
	int		has_single_newline;

	buffer = NULL;
	size = 0;
	has_single_newline = 0;
	if (!read_page(buffer, &fd, &size))
		return (0);
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
	if (support_inclm(support, buffer, &line) == NULL)
		return (NULL);
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

int	process_stdin_line(t_map *map, t_stdin *std)
{
	char	*line;
	int		line_width;

	line = read_from_buffer(&std->buffer, &std->buffer_pos, &std->buffer_size);
	if (!line)
	{
		while (std->i > 0)
			free(map->grid[--(std->i)]);
		free(map->grid);
		free(std->buffer);
		return (0);
	}
	line_width = check_line(std->line, map, map->width);
	if (line_width == 0)
	{
		free(std->line);
		while (std->i > 0)
			free(map->grid[--(std->i)]);
		free(map->grid);
		return (free(std->buffer), 0);
	}
	if (map->width == -1)
		map->width = line_width;
	map->grid[(std->i)++] = std->line;
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
		if (!process_stdin_line(map, &stdin))
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
