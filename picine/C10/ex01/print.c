/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:39:29 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/26 18:16:31 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	print_err(char *prog_name, char *msg, char *pathname)
{
	ft_putstr(prog_name);
	ft_putstr(": ");
	if (pathname)
	{
		ft_putstr(pathname);
		ft_putstr(": ");
	}
	ft_putstr(msg);
	ft_putstr("\n");
}

void	print_errno(char *prog_name, int errnum, char *pathname)
{
	print_err(prog_name, strerror(errnum), pathname);
}
