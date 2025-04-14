/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:05:23 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/26 23:10:51 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_open(t_tail_opts *opts)
{
	int	fd;

	fd = open(opts->pathname, O_RDONLY);
	if (fd == -1)
		print_open_err(opts, errno);
	return (fd);
}

ssize_t	ft_read(t_tail_opts *opts)
{
	ssize_t	read_bytes;

	read_bytes = read(opts->fd, opts->buf, BUF_LEN);
	if (read_bytes < 0)
		print_err_with_file(opts, errno);
	return (read_bytes);
}

ssize_t	ft_write(t_tail_opts *opts, int fd, char *buf, unsigned long cnt)
{
	ssize_t	write_bytes;

	write_bytes = write(fd, buf, cnt);
	if (write_bytes < 0)
		print_err_with_file(opts, errno);
	return (write_bytes);
}
