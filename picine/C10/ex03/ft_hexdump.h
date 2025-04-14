/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:40:26 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/30 16:17:17 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

# define BUF_LEN 16
# define OUTPUT_BUF_LEN 4096

typedef struct s_hexdump_ctx
{
	char			*prog_name;
	char			**pathnames;
	char			*pathname;
	int				pathcnt;
	int				pathcur;
	unsigned char	buf[BUF_LEN];
	unsigned char	prev_buf[BUF_LEN];
	unsigned char	output_buf[OUTPUT_BUF_LEN];
	int				fd;
	ssize_t			buf_size;
	ssize_t			total_size;
	ssize_t			output_buf_size;
	int				is_all_failed;
	int				is_first_line;
	int				printed_same_data_marker;
	int				mode_c;
}					t_hexdump_ctx;

void				ft_putstr(char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_strlen(char *str);

void				print_err(t_hexdump_ctx *ctx, char *msg);
void				print_errno(t_hexdump_ctx *ctx, int errnum);
void				print_errno_with_file(t_hexdump_ctx *ctx, int errnum);

void				buffered_putstr(t_hexdump_ctx *ctx, char *str);
void				buffered_write(t_hexdump_ctx *ctx, void *data, size_t len);
void				buffered_flush(t_hexdump_ctx *ctx);

int					process_hexdump(t_hexdump_ctx *ctx);
int					load_files(t_hexdump_ctx *ctx);

int					ft_open(t_hexdump_ctx *ctx);
ssize_t				ft_read(t_hexdump_ctx *ctx);
int					ft_close(t_hexdump_ctx *ctx);

void				render_index(t_hexdump_ctx *ctx);
void				render_hex(t_hexdump_ctx *ctx);
void				render_hex_c(t_hexdump_ctx *ctx);
void				render_ascii(t_hexdump_ctx *ctx);
void				render_total_size(t_hexdump_ctx *ctx);
void				render_line(t_hexdump_ctx *ctx);

void				copy_buf(t_hexdump_ctx *ctx);
int					compare_prev_buf(t_hexdump_ctx *ctx);
unsigned char		*build_hex(unsigned char *buf, ssize_t n, int digits);
unsigned int		set_hex(unsigned char *buf, unsigned char c,
						unsigned int i);

#endif
