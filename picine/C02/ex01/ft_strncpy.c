/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:08:22 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/18 08:13:47 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
// int	main(void)
// {
// 	char src[] = "I want to be able to write programcode of C language.";
// 	char dest[100];
// 	ft_strncpy(dest, src, 6);
// 	dest[6] = '\0';
// 	printf("%s\n", dest);

// 	ft_strncpy(dest, src, 70);
// 	printf("%s\n", dest);
// }