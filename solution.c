/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:01:18 by skarev            #+#    #+#             */
/*   Updated: 2018/05/10 22:01:18 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*solution(t_tetri *tetri)
{
	t_map	*map;
	int		size;

	size = min_map_size(count_list(tetri) * 4);
	map = map_creation(size);
	while (!algoooo(tetri, map))
	{
		size += 1;
		free_map(map);
		map = map_creation(size);
	}
	return (map);
}

void		set_place(t_tetri *tetri, t_map *map, int k, int l)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 3)
	{
		map->array[k + tetri->y[j]][l + tetri->x[i]] = tetri->c;
		i++;
		j++;
	}
}

int			check_place(t_map *map, t_tetri *tetri, int k, int l)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((k + tetri->height) >= map->size || ((l + tetri->weight) >= map->size))
		return (0);
	while (i <= 3)
	{
		if (map->array[tetri->y[i] + k][tetri->x[j] + l] != '.')
			return (0);
		j++;
		i++;
	}
	return (1);
}

void		clean_place(t_map *map, char c)
{
	int i;
	int j;

	i = 0;
	while (map->array[i])
	{
		j = -1;
		while (map->array[i][++j])
			if (map->array[i][j] == c)
				map->array[i][j] = '.';
		i++;
	}
}

int			algoooo(t_tetri *tetri, t_map *map)
{
	int i;
	int j;

	if (!tetri->next)
		return (1);
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (check_place(map, tetri, i, j))
			{
				set_place(tetri, map, i, j);
				if (algoooo(tetri->next, map))
					return (1);
				else
					clean_place(map, tetri->c);
			}
			j++;
		}
		i++;
	}
	return (0);
}
