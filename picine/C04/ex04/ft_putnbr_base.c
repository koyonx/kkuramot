/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:47:10 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/19 20:33:37 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\n' || base[1] == '\n')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i > 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		length;
	char	c;

	length = 0;
	if (!check(base))
		return ;
	while (base[length] != '\0')
		length++;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base(-(nbr / length), base);
		ft_putnbr_base(-(nbr % length), base);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= length)
		ft_putnbr_base(nbr / length, base);
	c = base[nbr % length];
	write(1, &c, 1);
}

// int	main(void)
// {
// 	ft_putnbr_base(42, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "0123456789ABCDEF");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "poneyvif");
// 	write(1, "\n", 1);
// 	return (0);
// }