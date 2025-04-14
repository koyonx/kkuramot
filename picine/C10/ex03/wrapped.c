/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:05:23 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/30 16:17:43 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_open(t_hexdump_ctx *ctx)
{
	int	fd;

	fd = open(ctx->pathname, O_RDONLY);
	if (fd == -1)
		print_errno_with_file(ctx, errno);
	return (fd);
}

ssize_t	ft_read(t_hexdump_ctx *ctx)
{
	ssize_t	read_bytes;

	read_bytes = read(ctx->fd, ctx->buf + ctx->buf_size, BUF_LEN
			- ctx->buf_size);
	if (read_bytes < 0)
		print_errno_with_file(ctx, errno);
	return (read_bytes);
}

int	ft_close(t_hexdump_ctx *ctx)
{
	int	status;

	status = 0;
	if (ctx->fd > 2)
		status = close(ctx->fd);
	ctx->fd = -1;
	return (status);
}
