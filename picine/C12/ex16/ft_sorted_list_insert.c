/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:18:11 by ttokuda           #+#    #+#             */
/*   Updated: 2025/04/01 10:05:20 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	insert_elem(t_list **begin_list, t_list *elem, int (*cmp)())
{
	t_list	*cur;
	t_list	*prev_elem;

	cur = *begin_list;
	prev_elem = 0;
	while (cur)
	{
		if (cmp(cur->data, elem->data) > 0)
		{
			elem->next = cur;
			if (prev_elem)
				prev_elem->next = elem;
			else
				*begin_list = elem;
			break ;
		}
		prev_elem = cur;
		cur = cur->next;
	}
	if (!cur)
		prev_elem->next = elem;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (!*begin_list)
	{
		*begin_list = elem;
		return ;
	}
	insert_elem(begin_list, elem, cmp);
}
