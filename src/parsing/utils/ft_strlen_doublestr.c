/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_doublestr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:03 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 15:13:50 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	check_number_of_array(char **ceiling_floor_data)
{
// LIBFT
	int	i;

	i = 0;
	while (ceiling_floor_data[i])
		i++;
	return (i);
}
