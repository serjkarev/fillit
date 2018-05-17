/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:13:36 by skarev            #+#    #+#             */
/*   Updated: 2018/03/24 15:13:44 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}
