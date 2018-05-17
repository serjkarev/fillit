/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:21:18 by skarev            #+#    #+#             */
/*   Updated: 2018/03/28 16:21:18 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (str1[i] && (i < len))
	{
		while ((str1[i + j] == str2[j]) && str2[j] && ((i + j) < len))
			j++;
		if (!str2[j])
			return ((char *)&str1[i]);
		j = 0;
		i++;
	}
	if (!str2[0])
		return ((char *)&str1[i]);
	return (NULL);
}
