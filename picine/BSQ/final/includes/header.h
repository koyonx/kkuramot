/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutinoue <yutinoue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:52:55 by kkuramot          #+#    #+#             */
/*   Updated: 2025/04/03 23:27:25 by yutinoue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	empty;
	char	obstacle;
	char	full;
	int		height;
	int		width;
	char	**grid;
}			t_map;

typedef struct s_square
{
	int		size;
	int		x;
	int		y;
}			t_square;

typedef struct s_support
{
	int		pos;
	int		size;
	int		start;
	int		i;
	int		line_len;
	int		j;
}			t_support;

typedef struct s_stdin
{
	char	*buffer;
	char	*line;
	int		buffer_size;
	int		buffer_pos;
	int		i;
}			t_stdin;

/* parser.c */
int			parse_header(char *line, t_map *map);
int			check_line(char *line, t_map *map, int width);
char		*read_line(int fd);
void		free_map(t_map *map);

/* parser_file.c */
int			check_final_newline(int fd);
int			init_parse_file(char *filename, t_map *map, int *fd, char **header);
int			allocate_grid(t_map *map, int fd);
int			process_line(t_map *map, int *i, int fd);
int			parse_file(char *filename, t_map *map);

/* parser_stdin2.c */
int			read_page(char *buffer, int *fd, int *size);
char		*support_inclm(t_support support, char *buffer, char **line);
void		solver_fix(int **dp, t_square *square, int i, int j);

/* parser_stdin.c */
int			check_stdin_final_newline(int fd, char **buffer_ptr, int *size_ptr);
char		*read_from_buffer(char **buffer_ptr, int *pos_ptr, int *size_ptr);
int			init_parse_stdin(t_map *map, char **buffer, int *buffer_size);
int			process_stdin_line(t_map *map, t_stdin *std);
int			parse_stdin(t_map *map);

/* solver.c */
void		init_dp(int ***dp, t_map *map, t_square *square);
void		fill_dp(int **dp, t_map *map, t_square *square);
void		free_dp(int **dp, int height);
t_square	find_biggest_square(t_map *map);
void		fill_square(t_map *map, t_square square);

/* printer.c */
void		print_map(t_map *map);
void		print_error(void);

/* utils.c */
int			ft_atoi(char *str);
void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
char		*ft_strdup(char *src);

/* other.c */
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_realloc(void *ptr, size_t size);
off_t		ft_lseek(int fd, off_t offset, int whence);

#endif
