/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:41:22 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/17 10:19:27 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	char	num[10];
	int		i;

	i = 0;
	while (i < n)
	{
		num[i] = '0' + i;
		i++;
	}
	while (1)
	{
		write(1, num, n);
		if (num[0] == '9' - n + 1)
			break ;
		write(1, ", ", 2);
		i = n - 1;
		while (i >= 0 && num[i] == '9' - (n - i - 1))
			i--;
		num[i]++;
		while (++i < n)
			num[i] = num[i - 1] + 1;
	}
}

// int	main(void)
// {
// 	ft_print_combn(3);
// 	return (0);
// }
