/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkuroda <shkuroda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:35:39 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/31 23:32:06 by shkuroda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numlib.h"
#include <stdlib.h>
#include <unistd.h>

int			tmp_check(char *block, t_dict_entry *dict, int *first);
int			teen_check(char *block, t_dict_entry *dict, int *first);
int			tens_check(char *block, t_dict_entry *dict, int *first);
int			ones_check(char *block, t_dict_entry *dict, int *first);

int			print_token(char *key, t_dict_entry *dict, int *first);
void		print_str(const char *s);
char		*make_scale(int count, int i);

char		*find_in_dict(char *key, t_dict_entry *dict);

static int	print_hundreds(char *block, t_dict_entry *dict, int *first)
{
	if (block[0] != '0')
	{
		if (tmp_check(block, dict, first) == 0)
			return (0);
	}
	if (block[1] == '1')
	{
		if (teen_check(block, dict, first) == 0)
			return (0);
	}
	else
	{
		if (block[1] != '0')
			if (tens_check(block, dict, first) == 0)
				return (0);
		if (block[2] != '0')
			if (ones_check(block, dict, first) == 0)
				return (0);
	}
	return (1);
}

static int	process_blocks(char **blocks, int count, t_dict_entry *dict, int i)
{
	int		first;
	char	*scale;

	first = 1;
	scale = NULL;
	while (i < count)
	{
		if (blocks[i][0] != '0' || blocks[i][1] != '0' || blocks[i][2] != '0')
		{
			scale = make_scale(count, i);
			if (!scale || !find_in_dict(scale, dict))
				return (free(scale), 0);
			if (!print_hundreds(blocks[i], dict, &first))
				return (free(scale), 0);
			if (i < count - 1)
			{
				if (!print_token(scale, dict, &first))
					return (free(scale), 0);
			}
			free(scale);
		}
		i++;
	}
	return (1);
}

static char	**split_by_threes(char *num, int *count)
{
	int		len;
	char	**blocks;
	int		i;
	int		pad;

	len = 0;
	while (num[len])
		len++;
	*count = (len + 2) / 3;
	pad = *count * 3 - len;
	blocks = malloc(sizeof(char *) * (*count));
	if (!blocks)
		return (NULL);
	i = 0;
	while (i < *count)
	{
		blocks[i] = make_new_line(num, i, pad);
		if (!blocks[i++])
		{
			while (i > 0)
				free(blocks[--i]);
			return (free(blocks), NULL);
		}
	}
	return (blocks);
}

int	print_number_in_words(char *num_str, t_dict_entry *dict)
{
	char	**blocks;
	int		count;
	int		i;

	i = 0;
	if (num_str[0] == '0' && num_str[1] == '\0')
	{
		return (print_token("0", dict, &i));
	}
	blocks = split_by_threes(num_str, &count);
	if (!blocks)
		return (write(1, "Dict Error\n", 11), 0);
	if (!process_blocks(blocks, count, dict, 0))
	{
		while (i < count)
			free(blocks[i++]);
		free(blocks);
		return (write(1, "Dict Error\n", 11), 0);
	}
	while (i < count)
	{
		free(blocks[i]);
		i++;
	}
	return (free(blocks), 1);
}
