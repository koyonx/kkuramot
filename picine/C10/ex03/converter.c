/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoku <cstoku@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:23:40 by cstoku            #+#    #+#             */
/*   Updated: 2025/03/29 17:05:47 by cstoku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

unsigned int	to_hex(unsigned char *buf, ssize_t n)
{
	unsigned int	i;
	ssize_t			p;
	unsigned char	c;

	p = 1;
	while (n / p >= 16)
	{
		p *= 16;
	}
	i = 0;
	while (p != 0)
	{
		c = n / p % 16;
		if (c < 10)
			c += '0';
		else
			c += 'a' - 10;
		buf[i] = c;
		p /= 16;
		i++;
	}
	return (i);
}

unsigned char	*build_hex(unsigned char *buf, ssize_t n, int digits)
{
	int				i;
	int				ndigits;
	unsigned char	hex[8];

	ndigits = to_hex(hex, n);
	i = 0;
	while (i < digits - ndigits)
	{
		buf[i] = '0';
		i++;
	}
	while (i < digits)
	{
		buf[i] = hex[i - digits + ndigits];
		i++;
	}
	while (i < 8)
	{
		buf[i] = 0;
		i++;
	}
	return (buf);
}
