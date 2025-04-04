/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidiribe <hidiribe@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-24 04:38:28 by hidiribe          #+#    #+#             */
/*   Updated: 2025-03-24 04:38:28 by hidiribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>
#include <unistd.h>

void	free_all(int **grid, int size, int *views)
{
	int	i;

	i = 0;
	while (i < size)
		free(grid[i++]);
	free(grid);
	free(views);
}

int	main(int argc, char **argv)
{
	int			**grid;
	int			*views;
	int			size;
	t_context	ctx;
	t_pos		pos;

	if (argc != 2)
		return (write(1, "Error\n", 6), 1);
	if (!validate_and_parse_input(argv[1], &views, &size))
		return (1);
	grid = allocate_grid(size);
	if (!grid)
		return (free(views), 1);
	ctx.grid = grid;
	ctx.views = views;
	ctx.size = size;
	pos.row = 0;
	pos.col = 0;
	if (!solve(&ctx, pos))
		write(1, "Error\n", 6);
	free_all(grid, size, views);
	return (0);
}
