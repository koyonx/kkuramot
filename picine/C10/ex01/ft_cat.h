/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:40:26 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/25 21:31:54 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H

# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

void	ft_putstr(char *str);
void	print_err(char *prog_name, char *msg, char *pathname);
void	print_errno(char *prog_name, int errnum, char *pathname);

#endif
