/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:51:27 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/14 17:26:00 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned long int	i;
	unsigned char		*p;

	i = 0;
	p = ptr;
	while (i < num)
	{
		p[i] = value;
		i++;
	}
	return ((void *)p);
}
