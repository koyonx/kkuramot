/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_visible_boxes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidiribe <hidiribe@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-24 04:38:17 by hidiribe          #+#    #+#             */
/*   Updated: 2025-03-24 04:38:17 by hidiribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible_boxes(int *line, int size)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < size)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}
