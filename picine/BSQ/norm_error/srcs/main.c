/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutinoue <yutinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:54:43 by kkuramot          #+#    #+#             */
/*   Updated: 2025/04/02 18:53:53 by yutinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_square(t_map *map, t_square *square)
{
	*square = find_biggest_square(map);
	fill_square(map, *square);
	print_map(map);
	free_map(map);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_square	square;
	int			i;
	int			success;

	if (argc == 1)
	{
		if (!parse_stdin(&map))
			return (print_error(), 1);
		create_square(&map, &square);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		success = parse_file(argv[i++], &map);
		if (success)
			create_square(&map, &square);
		else
			print_error();
		if (i < argc - 1)
			ft_putchar('\n');
	}
	return (0);
}
