/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:10:31 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/20 08:29:25 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	length;

	if (argc > 0)
	{
		length = 0;
		while (argv[0][length] != '\0')
		{
			write(1, &argv[0][length], 1);
			length++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
