/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:35:34 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/31 15:07:22 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numlib.h"
#include <stdlib.h>

void				free_dict(t_dict_entry *dict);
char				*some_lines(int j, int *strat, char *str);

static int	count_lines(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

static char	**split_lines(char *str, int *line_count, int i)
{
	char	**lines;
	int		j;
	int		start;

	*line_count = count_lines(str);
	lines = malloc(sizeof(char *) * (*line_count + 1));
	if (!lines)
		return (NULL);
	start = 0;
	j = 0;
	while (str[j++] != '\0')
	{
		if (str[j] == '\n')
		{
			lines[i] = some_lines(j, &start, str);
			if (!lines[i])
			{
				while (i > 0)
					free(lines[--i]);
				return (free(lines), NULL);
			}
			i++;
		}
	}
	return (lines[i] = NULL, lines);
}

static char	*str_trim(char *str)
{
	int		start;
	int		end;
	char	*res;
	int		i;

	start = 0;
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	end = start;
	while (str[end] && str[end] != '\0')
		end++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		end--;
	res = malloc(end - start + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}

static t_dict_entry	parse_entry(char *line)
{
	t_dict_entry	entry;
	int				i;
	int				colon;

	i = 0;
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		i++;
	colon = i;
	while (line[colon] && line[colon] != ':')
		colon++;
	if (!line[colon])
	{
		entry.key = NULL;
		entry.value = NULL;
		return (entry);
	}
	line[colon] = '\0';
	entry.key = str_trim(&line[i]);
	entry.value = str_trim(&line[colon + 1]);
	return (entry);
}

void	free_lines(char **lines);

t_dict_entry	*parse_dict(char *str)
{
	char			**lines;
	int				count;
	int				i;
	t_dict_entry	*dict;

	lines = split_lines(str, &count, 0);
	if (!lines)
		return (free_lines(lines), NULL);
	dict = malloc(sizeof(t_dict_entry) * (count + 1));
	if (!dict)
		return (free_lines(lines), NULL);
	i = 0;
	while (i < count)
	{
		dict[i] = parse_entry(lines[i]);
		if (!dict[i].key || !dict[i].value)
			return (free_dict(dict), free_lines(lines), NULL);
		i++;
	}
	free_lines(lines);
	dict[i].key = NULL;
	dict[i].value = NULL;
	return (dict);
}
