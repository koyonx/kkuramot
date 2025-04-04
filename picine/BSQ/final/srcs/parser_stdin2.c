/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stdin2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutinoue <yutinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:56:27 by yutinoue          #+#    #+#             */
/*   Updated: 2025/04/03 23:28:31 by yutinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	read_page(char *buffer, int *fd, int *size)
{
	int	read_size;

	while (1)
	{
		buffer = (char *)ft_realloc(buffer, *size + 8192);
		if (!buffer)
			return (0);
		read_size = read(*fd, buffer + *size, 8192);
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
	return (1);
}

char	*support_inclm(t_support support, char *buffer, char **line)
{
	while (support.i < support.size && buffer[support.i] != '\n')
		support.i++;
	support.line_len = support.i - support.start;
	*line = (char *)malloc(support.line_len + 1);
	if (!*line)
		return (NULL);
	support.j = 0;
	while (support.j < support.line_len)
	{
		*line[support.j] = buffer[support.start + support.j];
		support.j++;
	}
	return ((char *)1);
}

void	solver_fix(int **dp, t_square *square, int i, int j)
{
	int	min;

	min = dp[i - 1][j - 1];
	if (dp[i - 1][j] < min)
		min = dp[i - 1][j];
	if (dp[i][j - 1] < min)
		min = dp[i][j - 1];
	dp[i][j] = 1 + min;
	if (dp[i][j] > square->size)
	{
		square->size = dp[i][j];
		square->x = j - square->size + 1;
		square->y = i - square->size + 1;
	}
}
