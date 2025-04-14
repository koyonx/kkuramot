/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:47:35 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/28 13:51:26 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*cur;
	t_list	*last;
	t_list	*elem;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (*begin_list)
	{
		cur = *begin_list;
		while (cur)
		{
			last = cur;
			cur = cur->next;
		}
		last->next = elem;
	}
	else
		*begin_list = elem;
}
