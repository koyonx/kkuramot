/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:35:31 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/31 12:26:11 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numlib.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	print_dict_error(void)
{
	write(1, "Dict Error\n", 11);
}

static char	*allocate_buffer(void)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUF_SIZE + 1));
	if (!buf)
		return (NULL);
	return (buf);
}

static char	*copy_buffer(char *src, int size)
{
	char	*dst;
	int		i;

	dst = malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*load_dict(char *filename)
{
	int		fd;
	int		bytes;
	char	*buf;
	char	*dict;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = allocate_buffer();
	if (!buf)
		return (NULL);
	bytes = read(fd, buf, BUF_SIZE);
	close(fd);
	if (bytes <= 0)
		return (free(buf), NULL);
	buf[bytes] = '\0';
	dict = copy_buffer(buf, bytes);
	free(buf);
	return (dict);
}
