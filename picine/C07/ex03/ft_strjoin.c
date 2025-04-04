/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:13:46 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/25 11:39:20 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*midresult(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	if (size == 0)
		return ((char *)malloc(1));
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		len += j;
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				j++;
			len += j;
		}
		i++;
	}
	return ((char *)malloc(len + 1));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*result;
	int		k;

	k = 0;
	result = midresult(size, strs, sep);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[k++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				result[k++] = sep[j++];
		}
		i++;
	}
	result[k] = '\0';
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*strs[] = {"Hello", "42", "Piscine"};
// 	char	*sep;
// 	char	*result;

// 	sep = " | ";
// 	result = ft_strjoin(3, strs, sep);
// 	if (result)
// 	{
// 		printf("Joined string: %s\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("Memory allocation failed.\n");
// 	return (0);
// }
