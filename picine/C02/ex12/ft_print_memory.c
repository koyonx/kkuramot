/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochi <tochi@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-25 23:59:06 by tochi             #+#    #+#             */
/*   Updated: 2025-03-25 23:59:06 by tochi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char c)
{
	char	output[2];

	if (c / 16 >= 10)
		output[0] = c / 16 - 10 + 'a';
	else
		output[0] = c / 16 + '0';
	if (c % 16 >= 10)
		output[1] = c % 16 - 10 + 'a';
	else
		output[1] = c % 16 + '0';
	write(1, output, 2);
}

void	print_hex_line(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			print_hex(addr[i]);
			if (i % 2 == 1)
				write(1, " ", 1);
		}
		else
		{
			if (i % 2 == 1)
				write(1, "   ", 3);
			else
				write(1, "  ", 2);
		}
		i++;
	}
}

void	print_char_line(unsigned char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			if (addr[i] >= 32 && addr[i] <= 126)
				write(1, &addr[i], 1);
			else
				write(1, ".", 1);
		}
		i++;
	}
	write(1, "\n", 1);
}

void	print_addr(unsigned long long address)
{
	char	addr_str[17];
	int		i;

	i = 15;
	while (i >= 0)
	{
		addr_str[i] = "0123456789abcdef"[address % 16];
		address /= 16;
		i--;
	}
	addr_str[16] = ':';
	write(1, addr_str, 17);
	write(1, " ", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char		*ptr;
	unsigned int		i;
	unsigned long long	address;
	unsigned int		line_size;

	ptr = (unsigned char *)addr;
	i = 0;
	if (size == 0)
		return (addr);
	while (i < size)
	{
		address = (unsigned long long)ptr;
		print_addr(address);
		if (size - i > 16)
			line_size = 16;
		else
			line_size = size - i;
		print_hex_line(ptr, line_size);
		print_char_line(ptr, line_size);
		ptr += 16;
		i += 16;
	}
	return (addr);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	data[] = "Bonjour ,\fthis is a test for\t \v";

// 	unsigned int size = sizeof(data); // Null terminator is excluded
// 	ft_print_memory(data, size);
// 	return (0);
// }
