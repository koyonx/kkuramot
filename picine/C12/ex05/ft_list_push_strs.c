/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:05:44 by ttokuda           #+#    #+#             */
/*   Updated: 2025/04/01 10:05:45 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*elem;
	t_list	*next_elem;

	i = 0;
	next_elem = 0;
	while (i < size)
	{
		elem = ft_create_elem(strs[i++]);
		elem->next = next_elem;
		next_elem = elem;
	}
	return (next_elem);
}
