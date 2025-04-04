/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkuroda <shkuroda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:29:47 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/31 22:39:04 by shkuroda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numlib.h"

void	print_str(const char *s)
{
	while (*s)
		write(1, s++, 1);
}

char	*find_in_dict(char *key, t_dict_entry *dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i].key)
	{
		j = 0;
		while (dict[i].key[j] && key[j] && dict[i].key[j] == key[j])
			j++;
		if (dict[i].key[j] == '\0' && key[j] == '\0')
			return (dict[i].value);
		i++;
	}
	return (NULL);
}

int	print_token(char *key, t_dict_entry *dict, int *first)
{
	char	*word;

	word = find_in_dict(key, dict);
	if (!word)
		return (0);
	if (!*first)
		print_str(" ");
	print_str(word);
	*first = 0;
	return (1);
}

char	*make_scale(int count, int i)
{
	int		zeros;
	char	*scale;
	int		j;

	zeros = (count - i - 1) * 3;
	scale = (char *)malloc((zeros + 2) * sizeof(char));
	if (!scale)
		return (NULL);
	scale[0] = '1';
	j = 1;
	while (j <= zeros)
	{
		scale[j] = '0';
		j++;
	}
	scale[zeros + 1] = 0;
	return (scale);
}

char	*make_new_line(char *num, int i, int pad)
{
	char	*tmp;
	int		idx;
	int		j;

	tmp = malloc(4);
	if (!tmp)
		return (NULL);
	j = 0;
	while (j < 3)
	{
		idx = i * 3 + j - pad;
		if (idx < 0)
			tmp[j] = '0';
		else
			tmp[j] = num[idx];
		j++;
	}
	tmp[3] = 0;
	return (tmp);
}
