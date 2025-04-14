/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:40:26 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/27 16:34:28 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

# define BUF_LEN 33554432UL

typedef struct s_tail_opts
{
	char	*prog_name;
	char	**pathnames;
	char	*pathname;
	ssize_t	c;
	int		pathcnt;
	int		pathcur;
	char	*buf;
	char	*output;
	int		fd;
	ssize_t	output_size;
	int		is_printed;
}			t_tail_opts;

void		ft_putstr(char *str);
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);

void		print_header(t_tail_opts *opts);
void		print_err(t_tail_opts *opts, char *msg);
void		print_errno(t_tail_opts *opts, int errnum);
void		print_err_with_file(t_tail_opts *opts, int errnum);
void		print_open_err(t_tail_opts *opts, int errnum);

int			ft_open(t_tail_opts *opts);
int			ft_seek(t_tail_opts *opts, int fd, char *buf, unsigned long cnt);
ssize_t		ft_read(t_tail_opts *opts);
ssize_t		ft_write(t_tail_opts *opts, int fd, char *buf, unsigned long cnt);
long		load_file_len(t_tail_opts *opts, char *buf);
int			read_and_write(t_tail_opts *opts, int fd, char *buf,
				unsigned long file_len);
int			print_file(t_tail_opts *opts, char *buf, unsigned long file_len);
int			process_fd(t_tail_opts *opts);
int			process_tail(t_tail_opts *opts);
int			read_to_buffer(t_tail_opts *opts);
int			write_output(t_tail_opts *opts);

#endif
