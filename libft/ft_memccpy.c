/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:02:24 by skarev            #+#    #+#             */
/*   Updated: 2018/03/24 17:02:25 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ds;
	unsigned const char	*sr;

	i = 0;
	ds = (unsigned char*)dst;
	sr = (unsigned const char*)src;
	while (i < n)
	{
		ds[i] = sr[i];
		if (sr[i] == (unsigned char)c)
			return ((unsigned char*)dst + i + 1);
		i++;
	}
	return (NULL);
}
