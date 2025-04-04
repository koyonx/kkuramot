/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochi <tochi@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-25 01:51:55 by tochi             #+#    #+#             */
/*   Updated: 2025-03-25 01:51:55 by tochi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb % 16 >= 10)
	{
		ft_putchar((nb % 16) - 10 + 'a');
	}
	else
	{
		ft_putchar(nb % 16 + '0');
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			ft_putchar(str[i]);
		}
		else
		{
			ft_putchar('\\');
			ft_putnbr((unsigned char)str[i] / 16);
			ft_putnbr((unsigned char)str[i] % 16);
		}
		i++;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	ft_putstr_non_printable("Coucou\ntu \tvas \fbien ?");
// }
