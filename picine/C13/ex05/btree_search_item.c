/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:21:08 by ttokuda           #+#    #+#             */
/*   Updated: 2025/04/01 11:41:04 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *,
			void *))
{
	void	*res;

	if (!root)
		return (NULL);
	if (root->left)
	{
		res = btree_search_item(root->left, data_ref, cmpf);
		if (res)
			return (res);
	}
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (root->right)
	{
		res = btree_search_item(root->right, data_ref, cmpf);
		if (res)
			return (res);
	}
	return (NULL);
}
