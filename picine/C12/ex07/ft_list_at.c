/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:02:58 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/29 09:48:18 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
