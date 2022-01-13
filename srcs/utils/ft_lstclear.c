/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:22:03 by vbachele          #+#    #+#             */
/*   Updated: 2021/09/02 22:17:21 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_3d.h"

void	ft_lstclear(t_list **lst, void (*del)(t_list **))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = tmp;
	}
}
