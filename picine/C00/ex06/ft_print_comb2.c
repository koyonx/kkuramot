/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:41:14 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/17 09:02:19 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	num[5];
	int		i;
	int		j;

	i = 0;
	num[2] = ' ';
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			num[0] = '0' + (i / 10);
			num[1] = '0' + (i % 10);
			num[3] = '0' + (j / 10);
			num[4] = '0' + (j % 10);
			write(1, num, 5);
			if (i != 98 || j != 99)
			{
				write(1, ", ", 2);
			}
			j++;
		}
		i++;
	}
}
/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/