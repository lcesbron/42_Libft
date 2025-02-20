/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:31:34 by lcesbron          #+#    #+#             */
/*   Updated: 2025/02/20 15:33:52 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	lc_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ')
}