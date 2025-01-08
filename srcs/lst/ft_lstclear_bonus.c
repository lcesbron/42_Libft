/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:26:38 by lcesbron          #+#    #+#             */
/*   Updated: 2025/01/08 21:11:32 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stddef.h>
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst))
		return ;
	ft_lstclear(&((*lst)->next), (*del));
	if (*del)
		(*del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
