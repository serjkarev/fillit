/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:20:11 by skarev            #+#    #+#             */
/*   Updated: 2018/03/25 14:20:13 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (src[j] != '\0')
		{
			dst[i] = src[j];
			j++;
		}
		else
			dst[i] = src[j];
		i++;
	}
	return (dst);
}
