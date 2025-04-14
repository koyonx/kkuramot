/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokuda <ttokuda@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:26:47 by ttokuda           #+#    #+#             */
/*   Updated: 2025/03/29 20:12:16 by ttokuda          ###   ########.fr       */
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

t_list	*ft_list_swap(t_list *prev_elem, t_list *elem, t_list **begin_list)
{
	t_list	*tmp;
	t_list	*ret;

	if (prev_elem)
		prev_elem->next = elem->next;
	else
		*begin_list = elem->next;
	ret = elem->next;
	tmp = elem->next->next;
	elem->next->next = elem;
	elem->next = tmp;
	return (ret);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	int		j;
	int		len;
	t_list	*cur;
	t_list	*prev_elem;

	len = ft_list_size(*begin_list);
	i = 0;
	while (i < len)
	{
		cur = *begin_list;
		prev_elem = 0;
		j = 0;
		while (j++ < len - i - 1)
		{
			if (cmp(cur->data, cur->next->data) > 0)
				prev_elem = ft_list_swap(prev_elem, cur, begin_list);
			else
			{
				prev_elem = cur;
				cur = cur->next;
			}
		}
		i++;
	}
}

// void	f(void *fr)
// {
// 	fr = 0;
// }

// void	p(void *e)
// {
// 	char	*p;

// 	p = e;
// 	printf("%s\n", p);
// }

// void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
// void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
// t_list	*ft_list_push_strs(int size, char **strs);
// int		ft_strcmp(char *s1, char *s2);

// int	main(int argc, char **argv)
// {
// 	t_list	*elem;

// 	elem = ft_list_push_strs(argc - 1, argv + 1);
// 	ft_list_sort(&elem, ft_strcmp);
// 	ft_list_foreach(elem, p);
// 	ft_list_clear(elem, f);
// 	return (0);
// }
