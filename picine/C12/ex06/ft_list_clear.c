/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:58:11 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/29 09:47:46 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*elem;

	cur = begin_list;
	while (cur)
	{
		elem = cur;
		cur = elem->next;
		elem->next = 0;
		free_fct(elem->data);
		free(elem);
	}
}
