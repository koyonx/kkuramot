/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoku <cstoku@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:26:17 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/30 04:44:05 by cstoku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	render_index(t_hexdump_ctx *ctx)
{
	unsigned char	buf[8];
	int				digits;

	if (ctx->mode_c)
		digits = 8;
	else
		digits = 7;
	build_hex(buf, (ctx->total_size - 1) & (~0x0f), digits);
	buffered_write(ctx, buf, digits);
	if (ctx->mode_c)
		buffered_putstr(ctx, "  ");
	else
		buffered_putstr(ctx, " ");
}

void	render_hex(t_hexdump_ctx *ctx)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	buf[39];

	i = 0;
	while (i < 39)
		buf[i++] = ' ';
	i = 0;
	j = 0;
	while (i < ctx->buf_size)
	{
		if (i + 1 < ctx->buf_size)
			j = set_hex(buf, ctx->buf[i + 1], j);
		else
			j = set_hex(buf, 0, j);
		j = set_hex(buf, ctx->buf[i], j);
		j++;
		i += 2;
	}
	buffered_write(ctx, buf, 39);
}

void	render_hex_c(t_hexdump_ctx *ctx)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	buf[50];
	unsigned char	*base;
	unsigned char	c;

	base = (unsigned char *)"0123456789abcdef";
	i = 0;
	while (i < 50)
	{
		buf[i++] = ' ';
	}
	i = 0;
	j = 0;
	while (i < ctx->buf_size)
	{
		c = ctx->buf[i];
		buf[j++] = base[c / 16];
		buf[j++] = base[c % 16];
		j++;
		if ((i + 1) % 8 == 0)
			j++;
		i++;
	}
	buffered_write(ctx, buf, 50);
}

void	render_ascii(t_hexdump_ctx *ctx)
{
	int				i;
	unsigned char	c;

	buffered_putstr(ctx, "|");
	i = 0;
	while (i < ctx->buf_size)
	{
		c = ctx->buf[i];
		if (!(c >= 0x20 && c <= 0x7e))
			c = '.';
		buffered_write(ctx, &c, 1);
		i++;
	}
	buffered_putstr(ctx, "|");
}

void	render_total_size(t_hexdump_ctx *ctx)
{
	unsigned char	buf[8];
	int				digits;

	if (ctx->mode_c)
		digits = 8;
	else
		digits = 7;
	build_hex(buf, ctx->total_size, digits);
	buffered_write(ctx, buf, digits);
	buffered_putstr(ctx, "\n");
}
