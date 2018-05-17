/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_3000.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:55:54 by skarev            #+#    #+#             */
/*   Updated: 2018/05/05 16:55:54 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_valid_char(char *stock, int j)
{
	int	i;
	int	dash;
	int	dot;
	int	newline;

	i = 0;
	dash = 0;
	dot = 0;
	newline = 0;
	while (i + j < 20 + j && stock[i + j] != '\0')
	{
		if (stock[i + j] == '#')
			dash++;
		if (stock[i + j] == '.')
			dot++;
		if (stock[i + j] == '\n')
			newline++;
		i++;
	}
	if (dash == 4 && dot == 12 && newline == 4)
		return (1);
	return (0);
}

int		check_neighbors(char *stock, int j)
{
	int	i;
	int	neighbor;

	i = 0;
	neighbor = 0;
	while (i + j < 20 + j)
	{
		if (stock[i + j] == '#')
		{
			if (i + j + 1 < 20 + j && stock[i + j + 1] == '#')
				neighbor++;
			if (i + j - 1 >= 0 + j && stock[i + j - 1] == '#')
				neighbor++;
			if (i + j + 5 < 20 + j && stock[i + j + 5] == '#')
				neighbor++;
			if (i + j - 5 >= 0 + j && stock[i + j - 5] == '#')
				neighbor++;
		}
		i++;
	}
	if (neighbor == 6 || neighbor == 8)
		return (1);
	return (0);
}

int		check_str(char *stock)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!stock || !backslash_check(stock))
		return (0);
	while (stock[i + j] != '\0')
	{
		if (!(check_valid_char(stock, j)) || !(check_neighbors(stock, j)))
			return (0);
		i = 19;
		if (stock[i + j] == '\n' && stock[i + j + 1] == '\0')
			return (1);
		if (stock[i + j] == '\n' && stock[i + j + 1] == '\n' && \
					(stock[i + j + 2] == '.' || stock[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}

int		backslash_check(char *stock)
{
	int		i;

	i = 4;
	while (stock[i])
	{
		if (stock[i] != '\n')
			return (0);
		if (stock[i + 1] == '\n')
			i++;
		else
			i += 5;
	}
	return (1);
}
