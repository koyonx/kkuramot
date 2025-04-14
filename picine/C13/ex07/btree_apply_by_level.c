/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:27:41 by ttokuda           #+#    #+#             */
/*   Updated: 2025/04/01 18:07:47 by ttokuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_power(int nb, int power)
{
	int	i;
	int	res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 0;
	res = 1;
	while (i++ < power)
		res *= nb;
	return (res);
}

void	traversal(t_btree **nodes, int size, int current_level,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		i;
	int		next_size;
	int		is_first_elem;
	t_btree	**nexts;

	nexts = malloc(sizeof(t_btree *) * ft_power(2, current_level + 1));
	if (!nexts)
		return ;
	i = 0;
	next_size = 0;
	is_first_elem = 1;
	while (i < size)
	{
		applyf(nodes[i]->item, current_level, is_first_elem);
		if (is_first_elem)
			is_first_elem = 0;
		if (nodes[i]->left)
			nexts[next_size++] = nodes[i]->left;
		if (nodes[i]->right)
			nexts[next_size++] = nodes[i]->right;
		i++;
	}
	if (next_size)
		traversal(nexts, next_size, current_level + 1, applyf);
	free(nexts);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_btree	*wrapped[1];

	wrapped[0] = root;
	traversal(wrapped, 1, 0, applyf);
}
