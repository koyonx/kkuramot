/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:55:12 by kkuramot          #+#    #+#             */
/*   Updated: 2025/04/02 17:50:26 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_putstr(map->grid[i]);
		ft_putchar('\n');
		i++;
	}
}

void	print_error(void)
{
	ft_putstr("map error\n");
}
