/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:34:54 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/23 13:47:22 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	x;

	x = nb;
	if (nb == 1 || power == 0)
		return (1);
	else if (power < 0 || nb == 0)
		return (0);
	while (power > 1)
	{
		nb *= x;
		power--;
	}
	return (nb);
}

// int	main(void)
// {
// 	printf("2の二乗は%d\n", ft_iterative_power(2, 2));
// 	printf("3の三乗は%d\n", ft_iterative_power(3, 3));
// 	printf("0の二乗は%d\n", ft_iterative_power(0, 2));
// 	printf("-2の二乗は%d\n", ft_iterative_power(-2, 2));
// 	printf("1の二乗は%d\n", ft_iterative_power(1, 1));
// 	return (0);
// }
