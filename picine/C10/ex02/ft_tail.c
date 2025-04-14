/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:06:56 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/27 16:35:19 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	copy_buffer(char *dest, char *src, ssize_t n)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	shift_output_buffer(t_tail_opts *opts, ssize_t n)
{
	ssize_t	i;

	i = 0;
	while (i < opts->c - n)
	{
		opts->output[i] = opts->output[i + n];
		i++;
	}
}

int	read_to_buffer(t_tail_opts *opts)
{
	ssize_t	read_bytes;

	while (1)
	{
		read_bytes = ft_read(opts);
		if (read_bytes <= 0)
			return (!read_bytes);
		if (opts->output_size + read_bytes < opts->c)
			copy_buffer(opts->output + opts->output_size, opts->buf,
				read_bytes);
		else if (opts->c > read_bytes)
		{
			shift_output_buffer(opts, read_bytes);
			copy_buffer(opts->output + (opts->c - read_bytes), opts->buf,
				read_bytes);
		}
		else
			copy_buffer(opts->output, opts->buf + (read_bytes - opts->c),
				opts->c);
		if (opts->c < opts->output_size + read_bytes)
			opts->output_size = opts->c;
		else
			opts->output_size += read_bytes;
	}
}

int	write_output(t_tail_opts *opts)
{
	ssize_t	write_bytes;
	ssize_t	write_cnt;

	write_cnt = 0;
	while (write_cnt < opts->output_size)
	{
		write_bytes = ft_write(opts, 1, opts->output + write_cnt,
				opts->output_size - write_cnt);
		if (write_bytes < 0)
			return (0);
		write_cnt += write_bytes;
	}
	return (1);
}

int	process_fd(t_tail_opts *opts)
{
	int	status;

	opts->output_size = 0;
	if (opts->is_printed)
		ft_putstr("\n");
	if (opts->pathcnt > 1)
		print_header(opts);
	if (!read_to_buffer(opts))
		return (0);
	status = write_output(opts);
	opts->is_printed = 1;
	return (status);
}
