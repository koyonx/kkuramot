/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tochi <tochi@student.42tokyo.jp>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-17 21:14:47 by tochi             #+#    #+#             */
/*   Updated: 2025-03-17 21:14:47 by tochi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	count_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_num;

	i = 0;
	src_num = count_char(src);
	if (size == 0)
	{
		return (src_num);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size - 1)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (src_num);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char			a[] = "Hello, world!";
// 	char			b[] = "Hello, world!";
// 	size_t			len;
// 	unsigned int	num;
// 	char			dst[20];
// 	char			dest[20];

// 	len = strlcpy(dst, a, 20);
// 	printf("%s : %zu \n", dst, len);
// 	num = ft_strlcpy(dest, b, 20);
// 	printf("%s : %u \n", dst, num);
// 	return (0);
// }
// cc file -lbsd
