/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutinoue <yutinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:46:32 by kkuramot          #+#    #+#             */
/*   Updated: 2025/04/03 23:28:00 by yutinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_dp(int ***dp, t_map *map, t_square *square)
{
	int	i;
	int	j;

	*dp = (int **)malloc(sizeof(int *) * map->height);
	i = 0;
	while (i < map->height)
	{
		(*dp)[i] = (int *)malloc(sizeof(int) * map->width);
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == map->obstacle)
				(*dp)[i][j] = 0;
			else
				(*dp)[i][j] = 1;
			if ((*dp)[i][j] == 1 && square->size == 0)
			{
				square->size = 1;
				square->x = j;
				square->y = i;
			}
			j++;
		}
		i++;
	}
}

void	fill_dp(int **dp, t_map *map, t_square *square)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->height)
	{
		j = 1;
		while (j < map->width)
		{
			if (map->grid[i][j] == map->empty)
			{
				solver_fix(dp, square, i, j);
			}
			j++;
		}
		i++;
	}
}

void	free_dp(int **dp, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

t_square	find_biggest_square(t_map *map)
{
	int			**dp;
	t_square	square;

	square.size = 0;
	square.x = 0;
	square.y = 0;
	init_dp(&dp, map, &square);
	fill_dp(dp, map, &square);
	free_dp(dp, map->height);
	return (square);
}

void	fill_square(t_map *map, t_square square)
{
	int	i;
	int	j;

	i = square.y;
	while (i < square.y + square.size)
	{
		j = square.x;
		while (j < square.x + square.size)
		{
			map->grid[i][j] = map->full;
			j++;
		}
		i++;
	}
}
