/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:23:22 by ttokuda           #+#    #+#             */
/*   Updated: 2025/04/01 10:58:41 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	cur = *begin_list1;
	while (cur->next)
		cur = cur->next;
	cur->next = begin_list2;
}
