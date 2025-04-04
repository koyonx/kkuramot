/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:22:39 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/21 09:36:16 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_solution(int board[])
{
	char	output[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		output[i] = board[i] + '0';
		i++;
	}
	write(1, output, 10);
	write(1, "\n", 1);
}

int	is_safe(int board[], int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col || board[i] - i == col - row || board[i] + i == col
			+ row)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int board[], int row, int *count)
{
	int	col;

	if (row == 10)
	{
		print_solution(board);
		(*count)++;
		return ;
	}
	col = 0;
	while (col < 10)
	{
		if (is_safe(board, row, col))
		{
			board[row] = col;
			solve(board, row + 1, count);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	count;
	int	board[10];

	count = 0;
	solve(board, 0, &count);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_ten_queens_puzzle());
// 	return (0);
// }