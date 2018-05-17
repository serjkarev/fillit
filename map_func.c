/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:03:27 by skarev            #+#    #+#             */
/*   Updated: 2018/05/10 22:03:33 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_list(t_tetri *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i - 1);
}

int			min_map_size(int quant)
{
	int size;

	size = 2;
	while (size * size < quant)
		size++;
	return (size);
}

t_map		*map_creation(int size)
{
	t_map	*map;
	int		i;

	map = (t_map*)malloc(sizeof(t_map));
	i = 0;
	map->size = size;
	map->array = (char**)malloc(sizeof(char*) * (map->size + 1));
	map->array[map->size] = NULL;
	while (i < map->size)
	{
		map->array[i] = (char*)malloc(sizeof(char) * map->size);
		ft_memset(map->array[i], '.', map->size);
		i++;
	}
	return (map);
}

void		free_map(t_map *map)
{
	int l;

	l = 0;
	while (l <= map->size)
	{
		ft_memdel((void **)&(map->array[l]));
		l++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

void		out_print(t_map *map)
{
	int	i;
	int j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			write(1, &map->array[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
