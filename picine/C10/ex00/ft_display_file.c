/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:36:40 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/26 19:27:44 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	print_fd(int fd)
{
	int		size;
	char	buf[1024];

	size = 1;
	while (size > 0)
	{
		size = read(fd, buf, 1024);
		if (size == -1)
			return (-1);
		else if (size > 0)
		{
			if (write(1, buf, size) == -1)
				return (-1);
		}
	}
	return (0);
}

int	display_file(char *pathname)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (print_fd(fd))
	{
		close(fd);
		return (-1);
	}
	return (close(fd));
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	else if (display_file(argv[1]))
	{
		ft_putstr("Cannot read file.\n");
		return (1);
	}
	return (0);
}
