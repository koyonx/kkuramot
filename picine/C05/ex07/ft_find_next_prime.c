/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:55:04 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/22 10:17:25 by kkuramot         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (nb % 2 == 0 && nb != 2)
		nb++;
	while (!ft_is_prime(nb))
		nb += 2;
	return (nb);
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_find_next_prime(3));
// 	printf("%d\n", ft_find_next_prime(11));
// 	printf("%d\n", ft_find_next_prime(15));
// 	printf("%d\n", ft_find_next_prime(20));
// 	printf("%d\n", ft_find_next_prime(-5));
// 	return (0);
// }
