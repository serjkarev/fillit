/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:54:02 by skarev            #+#    #+#             */
/*   Updated: 2018/05/05 16:54:03 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_tetri(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			res++;
		i++;
	}
	return (res / 4);
}

void		coordinates_tetri(t_tetri **tmp, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

t_tetri		*struct_tetri(char *str)
{
	int		quantity;
	int		piece;
	char	c;
	t_tetri	*tmp;
	t_tetri	*head;

	piece = 0;
	c = 'A';
	if ((quantity = count_tetri(str)) > 26)
		return (NULL);
	if (!(head = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	tmp = head;
	while (quantity > 0)
	{
		tmp->c = c;
		coordinates_tetri(&tmp, ft_strsub(str, piece, 20));
		if (!(tmp->next = (t_tetri*)malloc(sizeof(t_tetri))))
			return (NULL);
		tmp = tmp->next;
		quantity--;
		c++;
		piece = piece + 21;
	}
	return (head);
}
