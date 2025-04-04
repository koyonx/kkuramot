/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidiribe <hidiribe@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-24 04:37:44 by hidiribe          #+#    #+#             */
/*   Updated: 2025-03-24 04:37:44 by hidiribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	**allocate_grid(int size)
{
	int	**grid;
	int	i;
	int	j;

	i = 0;
	grid = malloc(sizeof(int *) * size);
	if (!grid)
		return (write(1, "Error\n", 6), NULL);
	while (i < size)
	{
		grid[i] = malloc(sizeof(int) * size);
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			return (free(grid), write(1, "Error\n", 6), NULL);
		}
		j = 0;
		while (j < size)
			grid[i][j++] = 0;
		i++;
	}
	return (grid);
}
