/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:38:45 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/18 14:07:21 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s1[] = "great";
// 	char s2[] = "bad";
// 	char s3[] = "great";
// 	char s4[] = "Great";
// 	char s5[] = "greay";
// 	printf("%d\n", ft_strncmp(s1, s2, 4));
// 	printf("%d\n", ft_strncmp(s1, s3, 4));
// 	printf("%d\n", ft_strncmp(s1, s4, 4));
// 	printf("%d\n", ft_strncmp(s1, s5, 4));
// }