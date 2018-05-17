/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:58:08 by skarev            #+#    #+#             */
/*   Updated: 2018/05/05 16:58:08 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_x_min(t_tetri *tmp)
{
	int		i;
	int		j;
	int		min;

	i = 0;
	j = 0;
	min = tmp->x[i];
	while (i < 3)
	{
		if (tmp->x[i] < tmp->x[j])
		{
			min = tmp->x[i];
			j++;
		}
		i++;
	}
	return (min);
}

int			ft_y_min(t_tetri *tmp)
{
	int		i;
	int		j;
	int		min;

	i = 0;
	j = 0;
	min = tmp->y[i];
	while (i < 3)
	{
		if (tmp->y[i] < tmp->y[j])
		{
			min = tmp->y[i];
			j++;
		}
		i++;
	}
	return (min);
}

t_tetri		*zero_position(t_tetri *stock)
{
	int		i;
	int		x_min;
	int		y_min;
	t_tetri	*head;

	i = 0;
	if (!(head = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	head = stock;
	while (stock->next)
	{
		x_min = ft_x_min(stock);
		y_min = ft_y_min(stock);
		while (i < 4)
		{
			stock->x[i] = stock->x[i] - x_min;
			stock->y[i] = stock->y[i] - y_min;
			i++;
		}
		i = 0;
		ft_x_max(stock);
		ft_y_max(stock);
		stock = stock->next;
	}
	return (head);
}

void		ft_x_max(t_tetri *stock)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	j = 0;
	max = stock->x[i];
	while (i <= 3)
	{
		if (stock->x[i] > stock->x[j])
		{
			max = stock->x[i];
			j++;
		}
		i++;
	}
	stock->weight = max;
}

void		ft_y_max(t_tetri *stock)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	j = 0;
	max = stock->y[i];
	while (i <= 3)
	{
		if (stock->y[i] > stock->y[j])
		{
			max = stock->y[i];
			j++;
		}
		i++;
	}
	stock->height = max;
}
