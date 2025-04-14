/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:13:19 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/28 13:45:26 by ttokuda          ###   ########.fr       */
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
