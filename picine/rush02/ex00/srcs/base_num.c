/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuramot <kkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:22:58 by kkuramot          #+#    #+#             */
/*   Updated: 2025/03/31 11:25:58 by kkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numlib.h"

int	print_token(char *key, t_dict_entry *dict, int *first);

int	tmp_check(char *block, t_dict_entry *dict, int *first)
{
	char	tmp[2];

	tmp[0] = block[0];
	tmp[1] = 0;
	if (!print_token(tmp, dict, first) || !print_token("100", dict, first))
		return (0);
	return (1);
}

int	teen_check(char *block, t_dict_entry *dict, int *first)
{
	char	teen[3];

	teen[0] = block[1];
	teen[1] = block[2];
	teen[2] = 0;
	if (!print_token(teen, dict, first))
		return (0);
	return (1);
}

int	tens_check(char *block, t_dict_entry *dict, int *first)
{
	char	tens[3];

	tens[0] = block[1];
	tens[1] = '0';
	tens[2] = 0;
	if (!print_token(tens, dict, first))
		return (0);
	return (1);
}

int	ones_check(char *block, t_dict_entry *dict, int *first)
{
	char	ones[2];

	ones[0] = block[2];
	ones[1] = 0;
	if (!print_token(ones, dict, first))
		return (0);
	return (1);
}
