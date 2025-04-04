/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:31:06 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/16 18:25:47 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a'
					&& str[i] <= 'z')))
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// // int	main(void)
// // {
// // 	printf("%d\n", ft_str_is_alpha("smartphone"));
// // 	printf("%d\n", ft_str_is_alpha("GalaxyS20"));
// // 	printf("%d\n", ft_str_is_alpha(""));
// // 	printf("%d\n", ft_str_is_alpha("iphone!"));
// // 	return (0);
// // }