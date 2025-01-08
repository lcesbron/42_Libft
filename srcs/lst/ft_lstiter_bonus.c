/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:01:40 by lcesbron          #+#    #+#             */
/*   Updated: 2025/01/08 21:11:51 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !(*f))
		return ;
	ft_lstiter(lst->next, (*f));
	(*f)(lst->content);
}
