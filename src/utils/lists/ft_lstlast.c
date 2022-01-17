/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:04:42 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 15:20:20 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_lstlast(t_map *map_lst)
{
	if (!map_lst)
		return (NULL);
	while (map_lst->next)
		map_lst = map_lst->next;
	return (map_lst);
}
