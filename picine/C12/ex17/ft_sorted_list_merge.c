/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:06:54 by ttokuda           #+#    #+#             */
/*   Updated: 2025/04/01 18:46:51 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*merge_one(t_list **cur1, t_list **cur2, int (*cmp)())
{
	t_list	*c1;
	t_list	*c2;
	t_list	*target;

	c1 = *cur1;
	c2 = *cur2;
	if (cmp(c1->data, c2->data) <= 0)
	{
		target = c1;
		*cur1 = c1->next;
	}
	else
	{
		target = c2;
		*cur2 = c2->next;
	}
	return (target);
}

t_list	*merge(t_list **cur1, t_list **cur2, t_list **prev, int (*cmp)())
{
	t_list	*head;
	t_list	*target;

	head = 0;
	while (*cur1 && *cur2)
	{
		target = merge_one(cur1, cur2, cmp);
		if (*prev)
			(*prev)->next = target;
		else
			head = target;
		*prev = target;
	}
	if (*prev)
	{
		if (*cur1)
			(*prev)->next = *cur1;
		if (*cur2)
			(*prev)->next = *cur2;
	}
	return (head);
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*head;
	t_list	*cur1;
	t_list	*cur2;
	t_list	*prev;

	cur1 = *begin_list1;
	cur2 = begin_list2;
	prev = 0;
	head = merge(&cur1, &cur2, &prev, cmp);
	if (head)
		*begin_list1 = head;
	else if (cur2)
		*begin_list1 = begin_list2;
}
