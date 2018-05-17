/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:26:28 by skarev            #+#    #+#             */
/*   Updated: 2018/03/29 18:26:30 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *tmp;

	tmp = (void *)malloc(size);
	if (tmp == NULL)
		return (NULL);
	ft_memset(tmp, 0, size);
	return (tmp);
}
