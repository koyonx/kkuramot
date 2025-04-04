/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 04:51:26 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/24 16:14:27 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	size_t	memory;
	char	*copy;
	int		i;

	memory = 0;
	while (src[memory] != '\0')
		memory++;
	memory = memory + 1;
	copy = (char *)malloc(memory * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *src = "Hello, World";
// 	char *dup = ft_strdup(src);

// 	if (dup)
// 	{
// 		printf("Original: %s\n", src);
// 		printf("Duplicate: %s\n", dup);
// 		free(dup);
// 		printf("Memory allocation failed.\n");
// 		return (0);
// 	}
// }