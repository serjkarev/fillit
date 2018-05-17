/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:46:37 by skarev            #+#    #+#             */
/*   Updated: 2018/03/30 17:46:38 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	fresh = (char *)malloc(size + 1);
	if (!fresh)
		return (0);
	ft_bzero(fresh, size + 1);
	return (fresh);
}
