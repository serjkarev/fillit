/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:36:59 by skarev            #+#    #+#             */
/*   Updated: 2018/04/11 17:36:59 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *link;

	tmp = *alst;
	while (tmp)
	{
		link = tmp->next;
		del((tmp->content), (tmp->content_size));
		free(tmp);
		tmp = link;
	}
	*alst = NULL;
}
