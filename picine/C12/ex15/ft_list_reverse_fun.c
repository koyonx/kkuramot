/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:13:17 by ttokuda           #+#    #+#             */
/*   Updated: 2025/04/01 15:30:14 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*cur;

	i = 0;
	cur = begin_list;
	while (cur)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*cur;

	if (!begin_list)
		return (0);
	i = 0;
	cur = begin_list;
	while (i++ < nbr)
	{
		if (!cur->next)
			return (0);
		cur = cur->next;
	}
	return (cur);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		len;
	int		i;
	void	*tmp;
	t_list	*e1;
	t_list	*e2;

	i = 0;
	len = ft_list_size(begin_list);
	while (i < len / 2)
	{
		e1 = ft_list_at(begin_list, i);
		e2 = ft_list_at(begin_list, len - i - 1);
		tmp = e1->data;
		e1->data = e2->data;
		e2->data = tmp;
		i++;
	}
}
