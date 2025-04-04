/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:13:43 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/24 17:09:13 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_num_length(int num, int base_len)
{
	int	len;

	len = (num <= 0);
	while (num)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

char	*allocate_result(int num, int base_len)
{
	int		len;
	char	*result;

	len = get_num_length(num, base_len);
	result = (char *)malloc(len + 1);
	if (result)
		result[len] = '\0';
	return (result);
}

void	fill_result(char *result, int num, char *base, int base_len)
{
	int	i;

	i = get_num_length(num, base_len) - 1;
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	while (num)
	{
		result[i] = base[num % base_len];
		num /= base_len;
		i--;
	}
}

char	*int_to_base(int num, char *base, int base_len)
{
	char	*result;

	result = allocate_result(num, base_len);
	if (!result)
		return (NULL);
	if (num == 0)
		result[0] = base[0];
	else
		fill_result(result, num, base, base_len);
	return (result);
}
int		is_valid_base(char *base);
int		base_to_int(char *str, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	num;
	int	base_len;

	base_len = 0;
	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	num = base_to_int(nbr, base_from);
	while (base_to[base_len])
		base_len++;
	return (int_to_base(num, base_to, base_len));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*result;

// 	result = ft_convert_base("101", "01", "0123456789ABCDEF");
// 	if (result)
// 	{
// 		printf("Converted: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Conversion failed.\n");
// 	}
// 	return (0);
// }
