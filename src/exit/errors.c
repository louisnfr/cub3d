/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:34:43 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/01 15:29:43 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message_walls(void)
{
	ft_putstr_fd("Error\nProblem with your walls in your file cub\n", 2);
}

void	error_message_floor_ceiling(void)
{
	ft_putstr_fd("Error\nProblem with your floor"
		"or ceiling in your file cub\n", 2);
}

void	error_message_map(void)
{
	ft_putstr_fd("Error\nProblem with your map in your file cub\n", 2);
}
