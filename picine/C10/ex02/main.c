/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:05:35 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/27 16:34:07 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	process_stdin(t_tail_opts *opts)
{
	opts->fd = 0;
	return (process_fd(opts));
}

int	process_file(t_tail_opts *opts)
{
	int	status;

	opts->fd = ft_open(opts);
	if (opts->fd == -1)
		return (-1);
	status = process_fd(opts);
	close(opts->fd);
	return (status);
}

int	process_files(t_tail_opts *opts)
{
	int	status;

	status = 1;
	if (opts->pathcnt > 0)
	{
		while (opts->pathcur < opts->pathcnt)
		{
			opts->pathname = opts->pathnames[opts->pathcur];
			if (ft_strcmp(opts->pathname, "-"))
				status &= process_file(opts);
			else
				status &= process_stdin(opts);
			opts->pathcur++;
		}
	}
	else
		status = process_stdin(opts);
	return (status);
}

int	process_tail(t_tail_opts *opts)
{
	int	status;

	opts->buf = malloc(BUF_LEN);
	opts->output = malloc(opts->c);
	if (!opts->buf || !opts->output)
	{
		print_errno(opts, errno);
		return (0);
	}
	status = process_files(opts);
	free(opts->buf);
	free(opts->output);
	return (status);
}

int	main(int argc, char *argv[])
{
	t_tail_opts	opts;

	opts.prog_name = argv[0];
	if (argc < 3)
	{
		print_err(&opts, "Too few arguments");
		return (1);
	}
	opts.c = ft_atoi(argv[2]);
	opts.pathcur = 0;
	opts.pathcnt = argc - 3;
	opts.pathnames = argv + 3;
	opts.is_printed = 0;
	if (opts.c > 0)
		return (!process_tail(&opts));
	else
		return (0);
}
