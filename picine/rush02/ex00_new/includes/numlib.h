/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:35:46 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/31 15:07:40 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMLIB_H
# define NUMLIB_H

# define DEFAULT_DICT "srcs/numbers.dict"
# define BUF_SIZE 4096
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict_entry
{
	char		*key;
	char		*value;
}				t_dict_entry;

char			*load_dict(char *filename);
void			print_dict_error(void);

t_dict_entry	*parse_dict(char *str);
void			free_dict(t_dict_entry *dict);

int				print_number_in_words(char *num_str, t_dict_entry *dict);
void			free_dict(t_dict_entry *dict);
char			*some_lines(int j, int *strat, char *str);
int				tmp_check(char *block, t_dict_entry *dict, int *first);
int				teen_check(char *block, t_dict_entry *dict, int *first);
int				tens_check(char *block, t_dict_entry *dict, int *first);
int				ones_check(char *block, t_dict_entry *dict, int *first);
int				print_token(char *key, t_dict_entry *dict, int *first);

int				print_token(char *key, t_dict_entry *dict, int *first);
void			print_str(const char *s);

char			*make_scale(int count, int i);
char			*make_new_line(char *num, int i, int pad);
char			*find_in_dict(char *key, t_dict_entry *dict);
void			free_lines(char **lines);

#endif
