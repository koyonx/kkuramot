/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:35:33 by kueda             #+#    #+#             */
/*   Updated: 2025/03/16 14:22:58 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_line(int x, char first, char mid, char last)
{
	int	i;

	if (x <= 0)
		return ;
	ft_putchar(first);
	i = 2;
	while (i < x)
	{
		ft_putchar(mid);
		i++;
	}
	if (x > 1)
		ft_putchar(last);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	j;

	if (x <= 0 || y <= 0)
	{
		write(1, "error\n", 6);
		return ;
	}
	print_line(x, '/', '*', '\\');
	j = 2;
	while (j < y)
	{
		print_line(x, '*', ' ', '*');
		j++;
	}
	if (y > 1)
		print_line(x, '\\', '*', '/');
}
