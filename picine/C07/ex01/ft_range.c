/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:13:55 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/24 16:14:32 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	size;

	i = 0;
	size = max - min;
	if (min >= max)
		return (NULL);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int min = 3;
// 	int max = 8;
// 	int *arr = ft_range(min, max);
// 	int i = 0;
// 	if (arr)
// 	{
// 		printf("ft_range(%d, %d):", min, max);
// 		while (i < (max - min))
// 		{
// 			printf("%d", arr[i]);
// 			i++;
// 			;
// 		}
// 		printf("\n");
// 		free(arr);
// 	}
// 	else
// 		printf("NULL returned (invalid range).\n");
// 	return (0);
// }