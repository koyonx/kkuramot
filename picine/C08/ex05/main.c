/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:36:42 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/21 15:36:46 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stock_str *arr;
	arr = ft_strs_to_tab(argc - 1, argv + 1);
	if (!arr)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	ft_show_tab(arr);
	return (0);
}