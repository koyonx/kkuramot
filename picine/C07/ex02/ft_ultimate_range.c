/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:13:52 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/24 16:15:31 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	size = max - min;
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(size * sizeof(int));
	if (!*range)
		return (-1);
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int *range;
// 	int min = 5;
// 	int max = 10;
// 	int size;
// 	int i = 0;

// 	size = ft_ultimate_range(&range, min, max);
// 	if (size > 0)
// 	{
// 		printf("ft_ultimate_range(%d, %d)", min, max);
// 		while (i < size)
// 		{
// 			printf("%d", range[i]);
// 			i++;
// 		}
// 		printf("\n");
// 		free(range);
// 	}
// 	else if (size == 0)
// 		printf("NULL returned (invalid range).\n");
// 	else
// 		printf("Memory allocation failed.\n");
// 	return (0);
// }