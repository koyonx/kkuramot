/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:17:30 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/30 16:17:12 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	open_file(t_hexdump_ctx *ctx)
{
	int	fd;

	ctx->pathcur++;
	if (ctx->pathcnt == 0)
	{
		if (ctx->pathcur == 0)
			ctx->fd = 0;
		else
			ctx->fd = -1;
	}
	else
	{
		while (ctx->pathcur < ctx->pathcnt && ctx->fd < 0)
		{
			ctx->pathname = ctx->pathnames[ctx->pathcur];
			fd = ft_open(ctx);
			if (fd > 0)
			{
				ctx->is_all_failed = 0;
				ctx->fd = fd;
			}
			else
				ctx->pathcur++;
		}
	}
}

int	read_file(t_hexdump_ctx *ctx)
{
	ssize_t	read_bytes;

	while (ctx->buf_size < BUF_LEN)
	{
		read_bytes = ft_read(ctx);
		if (read_bytes < 0)
		{
			ft_close(ctx);
			return (0);
		}
		else if (read_bytes == 0)
		{
			ft_close(ctx);
			break ;
		}
		ctx->buf_size += read_bytes;
		ctx->total_size += read_bytes;
	}
	return (1);
}

int	load_files(t_hexdump_ctx *ctx)
{
	ctx->buf_size = 0;
	while (ctx->buf_size < BUF_LEN)
	{
		if (ctx->fd < 0)
		{
			open_file(ctx);
			if (ctx->fd < 0)
				return (ctx->buf_size > 0);
		}
		read_file(ctx);
	}
	return (1);
}
