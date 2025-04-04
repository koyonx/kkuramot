/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:28:45 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/23 13:47:01 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (nb == 1 || power == 0)
		return (1);
	else if (power < 0 || nb == 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}

// int	main(void)
// {
// 	printf("2の二乗は%d\n", ft_recursive_power(2, 2));
// 	printf("3の三乗は%d\n", ft_recursive_power(3, 3));
// 	printf("0の二乗は%d\n", ft_recursive_power(0, 2));
// 	printf("-2の二乗は%d\n", ft_recursive_power(-2, 2));
// 	printf("1の二乗は%d\n", ft_recursive_power(0, 2));
// 	return (0);
// }
