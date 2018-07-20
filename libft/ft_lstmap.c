/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrigore <rgrigore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:26:16 by rgrigore          #+#    #+#             */
/*   Updated: 2017/12/09 10:28:27 by rgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*cp;
	t_list	*k;

	tmp = NULL;
	cp = NULL;
	if (lst)
	{
		k = f(lst);
		if ((tmp = ft_lstnew(k->content, k->content_size)))
		{
			cp = tmp;
			while ((lst = lst->next))
			{
				k = f(lst);
				if (!(tmp->next = ft_lstnew(k->content, k->content_size)))
					return (NULL);
				tmp = tmp->next;
			}
		}
	}
	return (cp);
}
