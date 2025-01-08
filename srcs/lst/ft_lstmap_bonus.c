/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:54 by lcesbron          #+#    #+#             */
/*   Updated: 2025/01/08 21:12:10 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stddef.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;
	void	*temp;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	list = (NULL);
	while (lst)
	{
		temp = (*f)(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			if (*del)
				(*del)(temp);
			ft_lstclear(&list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&list, new);
		lst = lst->next;
	}
	return (list);
}
