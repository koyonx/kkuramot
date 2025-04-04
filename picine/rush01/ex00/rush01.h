/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidiribe <hidiribe@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-24 04:38:46 by hidiribe          #+#    #+#             */
/*   Updated: 2025-03-24 04:38:46 by hidiribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

typedef struct s_context
{
	int	**grid;
	int	*views;
	int	size;
}		t_context;

typedef struct s_pos
{
	int	row;
	int	col;
}		t_pos;

typedef struct s_fill
{
	int	**grid;
	int	*line;
	int	size;
	int	offset;
	int	index;
}		t_fill;

int		count_visible_boxes(int *line, int size);
int		check_views(t_context *ctx);
int		is_solution_valid(t_context *ctx);
int		solve(t_context *ctx, t_pos pos);
int		validate_and_parse_input(char *arg, int **views, int *size);
int		**allocate_grid(int size);
void	print_grid(int **grid, int size);
int		check_dir(int **grid, int *views, int size, int offset);
void	fill_line(t_fill f);
void	free_all(int **grid, int size, int *views);

#endif
