/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:21:03 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 15:18:49 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*ft_lstnew(char *content)
{
	t_map	*Next;

	Next = malloc(sizeof(t_map));
	if (!Next)
		return (NULL);
	Next->line = content;
	Next->next = NULL;
	return (Next);
}
