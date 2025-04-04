/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidiribe <hidiribe@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-24 04:38:54 by hidiribe          #+#    #+#             */
/*   Updated: 2025-03-24 04:38:54 by hidiribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid(t_context *ctx, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < ctx->size)
	{
		if (ctx->grid[row][i] == num || ctx->grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

t_pos	get_next_position(t_pos pos, int size)
{
	t_pos	next;

	next.col = (pos.col + 1) % size;
	next.row = pos.row + (next.col == 0);
	return (next);
}

int	solve(t_context *ctx, t_pos pos)
{
	t_pos	next;
	int		num;

	num = 1;
	if (pos.row == ctx->size)
		return (is_solution_valid(ctx));
	while (num <= ctx->size)
	{
		if (is_valid(ctx, pos.row, pos.col, num))
		{
			ctx->grid[pos.row][pos.col] = num;
			next = get_next_position(pos, ctx->size);
			if (solve(ctx, next))
				return (1);
			ctx->grid[pos.row][pos.col] = 0;
		}
		num++;
	}
	return (0);
}
