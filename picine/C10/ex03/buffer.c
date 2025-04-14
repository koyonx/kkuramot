/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoku <cstoku@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 04:10:16 by cstoku            #+#    #+#             */
/*   Updated: 2025/03/30 04:40:14 by cstoku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	buffered_putstr(t_hexdump_ctx *ctx, char *str)
{
	int	len;

	len = ft_strlen(str);
	buffered_write(ctx, str, len);
}

void	buffered_write(t_hexdump_ctx *ctx, void *data, size_t len)
{
	size_t	i;
	char	*c_data;

	c_data = (char *)data;
	i = 0;
	while (i < len)
	{
		ctx->output_buf[ctx->output_buf_size++] = c_data[i++];
		if (ctx->output_buf_size == OUTPUT_BUF_LEN)
			buffered_flush(ctx);
	}
}

void	buffered_flush(t_hexdump_ctx *ctx)
{
	write(1, ctx->output_buf, ctx->output_buf_size);
	ctx->output_buf_size = 0;
}
