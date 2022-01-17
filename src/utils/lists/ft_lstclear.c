/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:22:03 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 15:20:20 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lstclear(t_map **map_lst, void (*del)(t_map **))
{
	t_map	*tmp;

	while (*map_lst)
	{
		tmp = (*map_lst)->next;
		ft_lstdelone(*map_lst, del);
		(*map_lst) = tmp;
	}
}
