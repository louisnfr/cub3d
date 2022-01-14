/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:21:03 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/14 17:26:00 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*Next;

	Next = malloc(sizeof(t_list));
	if (!Next)
		return (NULL);
	Next->line = content;
	Next->next = NULL;
	return (Next);
}
