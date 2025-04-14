/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:10:10 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/28 14:24:13 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*cur;
	t_list	*tmp;
	t_list	*prev_elem;

	cur = *begin_list;
	prev_elem = 0;
	while (cur)
	{
		tmp = cur->next;
		cur->next = prev_elem;
		prev_elem = cur;
		cur = tmp;
	}
	*begin_list = prev_elem;
}
