/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:42:16 by ttokuda           #+#    #+#             */
/*   Updated: 2025/04/01 18:46:27 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*free_elem(t_list *elem, void (*free_fct)(void *))
{
	t_list	*next;

	next = elem->next;
	free_fct(elem->data);
	free(elem);
	return (next);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*prev_elem;
	t_list	*first_elem;

	cur = *begin_list;
	first_elem = NULL;
	prev_elem = NULL;
	while (cur)
	{
		if (!cmp(cur->data, data_ref))
		{
			cur = free_elem(cur, free_fct);
			if (prev_elem)
				prev_elem->next = cur;
		}
		else
		{
			if (!first_elem)
				first_elem = cur;
			prev_elem = cur;
			cur = cur->next;
		}
	}
	*begin_list = first_elem;
}
