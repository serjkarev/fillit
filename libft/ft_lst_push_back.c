/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:37:57 by skarev            #+#    #+#             */
/*   Updated: 2018/04/15 18:37:58 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **begin_list, void *data)
{
	t_list *elem;

	elem = *begin_list;
	if (*begin_list)
	{
		while (elem->next)
			elem = elem->next;
		elem->next = ft_lst_create_elem(data);
	}
}
