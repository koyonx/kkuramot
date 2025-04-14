/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:36:40 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/28 15:12:56 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	print_fd(int fd)
{
	int		size;
	char	buf[4096];

	size = 1;
	while (size > 0)
	{
		size = read(fd, buf, 4096);
		if (size == -1)
			return (1);
		else if (size > 0)
		{
			if (write(1, buf, size) == -1)
				return (1);
		}
	}
	return (0);
}

int	process_file(char *prog_name, char *pathname)
{
	int	fd;

	if (pathname)
	{
		fd = open(pathname, O_RDONLY);
		if (fd == -1)
		{
			print_errno(prog_name, errno, pathname);
			return (0);
		}
	}
	else
		fd = 0;
	if (print_fd(fd))
	{
		print_errno(prog_name, errno, pathname);
		return (0);
	}
	if (close(fd))
	{
		print_errno(prog_name, errno, pathname);
		return (0);
	}
	return (1);
}

int	process_cat(char *prog_name, int pathcnt, char **pathnames)
{
	int	i;
	int	status;

	i = 0;
	status = 1;
	if (pathcnt == 0)
		status = process_file(prog_name, NULL);
	else
	{
		while (i < pathcnt)
		{
			status &= process_file(prog_name, pathnames[i]);
			i++;
		}
	}
	return (status);
}

int	main(int argc, char **argv)
{
	char	*prog_name;

	prog_name = argv[0];
	return (!process_cat(prog_name, argc - 1, argv + 1));
}
