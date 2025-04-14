/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoku <cstoku@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:05:35 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/30 04:35:21 by cstoku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	finalize(t_hexdump_ctx *ctx)
{
	int	status;

	status = 1;
	if (ctx->pathcnt > 0 && ctx->is_all_failed)
	{
		print_err(ctx, "all input file arguments failed");
		status = 0;
	}
	else if (ctx->total_size > 0)
		render_total_size(ctx);
	buffered_flush(ctx);
	return (status);
}

void	render_line(t_hexdump_ctx *ctx)
{
	if (compare_prev_buf(ctx) || ctx->is_first_line)
	{
		ctx->printed_same_data_marker = 0;
		render_index(ctx);
		if (ctx->mode_c)
		{
			render_hex_c(ctx);
			render_ascii(ctx);
		}
		else
			render_hex(ctx);
		buffered_putstr(ctx, "\n");
		copy_buf(ctx);
	}
	else if (!ctx->printed_same_data_marker)
	{
		buffered_putstr(ctx, "*\n");
		ctx->printed_same_data_marker = 1;
	}
	ctx->is_first_line = 0;
}

int	process_hexdump(t_hexdump_ctx *ctx)
{
	int	status;
	int	load_status;

	status = 1;
	while (1)
	{
		load_status = load_files(ctx);
		if (load_status <= 0)
		{
			status = load_status == 0;
			break ;
		}
		render_line(ctx);
	}
	status &= finalize(ctx);
	return (status);
}

void	init_ctx(t_hexdump_ctx *ctx, int argc, char **argv)
{
	ctx->pathcur = -1;
	ctx->fd = -1;
	ctx->is_all_failed = 1;
	ctx->buf_size = 0;
	ctx->total_size = 0;
	ctx->output_buf_size = 0;
	ctx->is_first_line = 1;
	ctx->printed_same_data_marker = 0;
	ctx->mode_c = 0;
	ctx->pathcnt = argc - 1;
	ctx->pathnames = argv + 1;
	if (argc > 1 && ft_strcmp(argv[1], "-C") == 0)
	{
		ctx->mode_c = 1;
		ctx->pathcnt -= 1;
		ctx->pathnames += 1;
	}
}

int	main(int argc, char *argv[])
{
	t_hexdump_ctx	ctx;

	ctx.prog_name = basename(argv[0]);
	init_ctx(&ctx, argc, argv);
	return (!process_hexdump(&ctx));
}
