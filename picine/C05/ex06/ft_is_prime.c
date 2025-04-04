/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:51:51 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/22 10:17:18 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	i;

	i = 3;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_is_prime(2));
// 	printf("%d\n", ft_is_prime(3));
// 	printf("%d\n", ft_is_prime(4));
// 	printf("%d\n", ft_is_prime(5));
// 	printf("%d\n", ft_is_prime(6));
// 	printf("%d\n", ft_is_prime(7));
// 	printf("%d\n", ft_is_prime(10));
// 	printf("%d\n", ft_is_prime(13));
// 	printf("%d\n", ft_is_prime(21));
// 	printf("%d\n", ft_is_prime(51));
// 	printf("%d\n", ft_is_prime(101));
// 	return (0);
// }