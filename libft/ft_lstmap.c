/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:38:06 by skarev            #+#    #+#             */
/*   Updated: 2018/04/11 17:38:07 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *newelem;
	t_list *ret;

	ret = NULL;
	if (!lst || !f)
		return (NULL);
	tmp = lst;
	while (tmp)
	{
		if (!ret)
		{
			ret = f(tmp);
			newelem = ret;
		}
		else
		{
			newelem->next = f(tmp);
			newelem = newelem->next;
		}
		tmp = tmp->next;
	}
	newelem->next = NULL;
	return (ret);
}
