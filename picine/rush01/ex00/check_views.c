/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_views.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidiribe <hidiribe@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-24 04:37:56 by hidiribe          #+#    #+#             */
/*   Updated: 2025-03-24 04:37:56 by hidiribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>

void	fill_line(t_fill f)
{
	int	j;

	j = 0;
	while (j < f.size)
	{
		if (f.offset < f.size)
			f.line[j] = f.grid[j][f.index];
		else if (f.offset < f.size * 2)
			f.line[j] = f.grid[f.size - 1 - j][f.index];
		else if (f.offset < f.size * 3)
			f.line[j] = f.grid[f.index][j];
		else
			f.line[j] = f.grid[f.index][f.size - 1 - j];
		j++;
	}
}

int	check_dir(int **grid, int *views, int size, int offset)
{
	int		*line;
	int		i;
	t_fill	f;

	i = 0;
	line = malloc(sizeof(int) * size);
	if (!line)
		return (0);
	f.grid = grid;
	f.line = line;
	f.size = size;
	f.offset = offset;
	while (i < size)
	{
		f.index = i;
		fill_line(f);
		if (count_visible_boxes(line, size) != views[offset + i])
			return (free(line), 0);
		i++;
	}
	free(line);
	return (1);
}

int	check_views(t_context *ctx)
{
	int	s;
	int	*v;
	int	**g;

	s = ctx->size;
	v = ctx->views;
	g = ctx->grid;
	if (!check_dir(g, v, s, 0))
		return (0);
	if (!check_dir(g, v, s, s))
		return (0);
	if (!check_dir(g, v, s, s * 2))
		return (0);
	if (!check_dir(g, v, s, s * 3))
		return (0);
	return (1);
}
