/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:14:09 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/31 15:07:08 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numlib.h"

void	free_dict(t_dict_entry *dict)
{
	int	i;

	i = 0;
	while (dict[i].key && dict[i].value)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}

char	*some_lines(int j, int *strat, char *str)
{
	char	*tmp;
	int		i;
	int		num;

	tmp = malloc((j - *strat + 1));
	if (!tmp)
		return (NULL);
	i = *strat;
	num = 0;
	while (i < j)
	{
		tmp[num] = str[i];
		i++;
		num++;
	}
	tmp[num] = '\0';
	*strat = j + 1;
	return (tmp);
}

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}