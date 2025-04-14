/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:39:29 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/26 23:09:50 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	print_header(t_tail_opts *opts)
{
	ft_putstr("==> ");
	if (opts->pathcnt != 0 && ft_strcmp(opts->pathname, "-"))
		ft_putstr(opts->pathname);
	else
		ft_putstr("standard input");
	ft_putstr(" <==\n");
}

void	print_err(t_tail_opts *opts, char *msg)
{
	ft_putstr(opts->prog_name);
	ft_putstr(": ");
	ft_putstr(msg);
	ft_putstr("\n");
}

void	print_errno(t_tail_opts *opts, int errnum)
{
	ft_putstr(opts->prog_name);
	ft_putstr(": ");
	ft_putstr(strerror(errnum));
	ft_putstr("\n");
}

void	print_err_with_file(t_tail_opts *opts, int errnum)
{
	ft_putstr(opts->prog_name);
	ft_putstr(": ");
	ft_putstr(opts->pathname);
	ft_putstr(": ");
	ft_putstr(strerror(errnum));
	ft_putstr("\n");
}

void	print_open_err(t_tail_opts *opts, int errnum)
{
	ft_putstr(opts->prog_name);
	ft_putstr(": cannot open '");
	ft_putstr(opts->pathname);
	ft_putstr("' for reading: ");
	ft_putstr(strerror(errnum));
	ft_putstr("\n");
}
