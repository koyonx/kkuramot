/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:35:36 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/31 15:02:04 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numlib.h"
#include <stdlib.h>
#include <unistd.h>

int		is_numeric(char *str);
void	print_error(void);
void	free_dict(t_dict_entry *dict);

int	main(int argc, char **argv)
{
	char			*dict_file;
	char			*dict_str;
	t_dict_entry	*dict;

	if (argc != 2 && argc != 3)
		return (print_error(), 1);
	if (!is_numeric(argv[argc - 1]))
		return (print_error(), 1);
	if (argc == 3)
		dict_file = argv[1];
	else
		dict_file = DEFAULT_DICT;
	dict_str = load_dict(dict_file);
	if (!dict_str)
		return (print_dict_error(), 2);
	dict = parse_dict(dict_str);
	free(dict_str);
	if (!dict)
		return (print_dict_error(), 3);
	print_number_in_words(argv[argc - 1], dict);
	write(1, "\n", 1);
	free_dict(dict);
	return (0);
}

int	is_numeric(char *str)
{
	int	i;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}
