/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:41:37 by ttokuda           #+#    #+#             */
/*   Updated: 2025/04/01 17:28:38 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	traversal(t_btree *node, int level, int max_level)
{
	int	tmp;

	if (!node)
		return (max_level);
	if (level > max_level)
		max_level = level;
	tmp = traversal(node->left, level + 1, max_level);
	if (tmp > max_level)
		max_level = tmp;
	tmp = traversal(node->right, level + 1, max_level);
	if (tmp > max_level)
		max_level = tmp;
	return (max_level);
}

int	btree_level_count(t_btree *root)
{
	return (traversal(root, 1, 0));
}
