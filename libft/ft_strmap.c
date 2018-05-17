/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:49:51 by skarev            #+#    #+#             */
/*   Updated: 2018/04/02 20:49:52 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (0);
	while (s[i])
	{
		tmp[i] = f(s[i]);
		i++;
	}
	tmp[i++] = '\0';
	return (tmp);
}
