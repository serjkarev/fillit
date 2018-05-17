/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:57:10 by skarev            #+#    #+#             */
/*   Updated: 2018/05/05 16:57:10 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*stock_str(int fd)
{
	int		i;
	int		j;
	char	c;
	char	*str;

	i = 0;
	str = NULL;
	j = read(fd, &c, 1);
	if (j < 0)
		return (NULL);
	if (j == 1)
	{
		if (!(str = (char*)malloc(sizeof(char) * 545)))
			return (NULL);
		while (j != 0)
		{
			str[i++] = c;
			j = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	if (i > 545)
		return (NULL);
	return (str);
}
