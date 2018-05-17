/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:58:45 by skarev            #+#    #+#             */
/*   Updated: 2018/03/24 18:58:46 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int i;

	i = 0;
	if (((unsigned char*)src) < ((unsigned char*)dst))
		while (len-- > 0)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	else
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	return ((unsigned char*)dst);
}
