/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:34:58 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/21 18:58:11 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	else
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
	return (nb);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("1の階乗は%d\n", ft_recursive_factorial(1));
// 	printf("10の階乗は%d\n", ft_recursive_factorial(10));
// 	printf("-1の階乗は%d\n", ft_recursive_factorial(-1));
// 	printf("0の階乗は%d\n", ft_recursive_factorial(0));
// 	return (0);
// }