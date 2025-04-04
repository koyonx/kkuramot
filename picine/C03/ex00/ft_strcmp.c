/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:22:59 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/18 05:58:40 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (s1[i] - s2[i]);
		}
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
// 	printf("%d\n", ft_strcmp(s1, s2));
// 	printf("%d\n", ft_strcmp(s1, s3));
// 	printf("%d\n", ft_strcmp(s1, s4));
// 	printf("%d\n", ft_strcmp(s1, s5));
// }