/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:54:49 by skarev            #+#    #+#             */
/*   Updated: 2018/04/05 16:54:50 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int		ft_wordnum(char const *s, char c)
{
	int i;
	int word;

	i = 1;
	word = 0;
	if (s[0] != c && s[0] != '\0')
		word++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			word++;
		i++;
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		w;
	int		j;
	char	**tmp;

	i = 0;
	if (!s || !c)
		return (NULL);
	w = ft_wordnum(s, c);
	tmp = (char**)malloc(sizeof(char*) * (w + 1));
	if (!tmp)
		return (NULL);
	while (i < w)
	{
		while (*s && *s == c)
			s++;
		j = 0;
		tmp[i] = (char*)malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
		while (*s && *s != c)
			tmp[i][j++] = *s++;
		tmp[i++][j] = '\0';
	}
	tmp[i] = 0;
	return (tmp);
}
