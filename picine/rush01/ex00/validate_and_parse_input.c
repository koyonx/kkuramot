/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_parse_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidiribe <hidiribe@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-24 04:39:02 by hidiribe          #+#    #+#             */
/*   Updated: 2025-03-24 04:39:02 by hidiribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	parse_input(char *str, int *views, int expected)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && j < expected)
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			views[j] = str[i] - '0';
			j++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (j == expected);
}

int	validate_and_parse_input(char *arg, int **views, int *size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if (arg[i] >= '1' && arg[i] <= '9')
			count++;
		i++;
	}
	if (count % 4 != 0 || count == 0)
		return (write(1, "Error\n", 6), 0);
	*size = count / 4;
	if (*size < 1 || *size > 9)
		return (write(1, "Error\n", 6), 0);
	*views = malloc(sizeof(int) * count);
	if (!*views)
		return (write(1, "Error\n", 6), 0);
	return (parse_input(arg, *views, count));
}
