/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:39:29 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/27 22:16:17 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_err(t_hexdump_ctx *ctx, char *msg)
{
	ft_putstr(ctx->prog_name);
	ft_putstr(": ");
	ft_putstr(msg);
	ft_putstr("\n");
}

void	print_errno(t_hexdump_ctx *ctx, int errnum)
{
	ft_putstr(ctx->prog_name);
	ft_putstr(": ");
	ft_putstr(strerror(errnum));
	ft_putstr("\n");
}

void	print_errno_with_file(t_hexdump_ctx *ctx, int errnum)
{
	ft_putstr(ctx->prog_name);
	ft_putstr(": ");
	ft_putstr(ctx->pathname);
	ft_putstr(": ");
	ft_putstr(strerror(errnum));
	ft_putstr("\n");
}
