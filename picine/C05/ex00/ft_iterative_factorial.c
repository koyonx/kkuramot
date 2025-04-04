/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:10:20 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/21 18:59:48 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	x;
	int	y;

	if (nb < 0)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	if (nb > 1)
	{
		x = 1;
		y = nb;
		while (y > x)
		{
			nb *= (y - x);
			x++;
		}
	}
	return (nb);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("1の階乗は%d\n", ft_iterative_factorial(1));
// 	printf("10の階乗は%d\n", ft_iterative_factorial(10));
// 	printf("-1の階乗は%d\n", ft_iterative_factorial(-1));
// 	printf("0の階乗は%d\n", ft_iterative_factorial(0));
// 	return (0);
// }