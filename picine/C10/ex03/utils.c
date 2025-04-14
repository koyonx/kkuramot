/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoku <cstoku@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:48:43 by cstoku            #+#    #+#             */
/*   Updated: 2025/03/29 18:41:35 by cstoku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	copy_buf(t_hexdump_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < BUF_LEN)
	{
		ctx->prev_buf[i] = ctx->buf[i];
		i++;
	}
}

int	compare_prev_buf(t_hexdump_ctx *ctx)
{
	int	i;

	if (ctx->buf_size != BUF_LEN)
		return (1);
	i = 0;
	while (i < BUF_LEN)
	{
		if (ctx->buf[i] != ctx->prev_buf[i])
			return (1);
		i++;
	}
	return (0);
}

unsigned int	set_hex(unsigned char *buf, unsigned char c, unsigned int i)
{
	unsigned char	*base;

	base = (unsigned char *)"0123456789abcdef";
	buf[i++] = base[c / 16];
	buf[i++] = base[c % 16];
	return (i);
}
