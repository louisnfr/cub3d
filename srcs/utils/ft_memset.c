/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:51:27 by vbachele          #+#    #+#             */
/*   Updated: 2021/09/02 22:20:01 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_3d.h"

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
