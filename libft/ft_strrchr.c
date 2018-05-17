/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:46:37 by skarev            #+#    #+#             */
/*   Updated: 2018/03/26 15:46:41 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*str;
	char		*buf;
	int			v;

	v = (char)c;
	buf = (char*)s;
	str = (char*)s;
	if (v == '\0')
	{
		while (*str != '\0')
			str++;
		return (str);
	}
	while (*str != '\0')
	{
		if (*str == v)
			buf = str;
		str++;
	}
	if (*buf == v)
		return (buf);
	return (NULL);
}
