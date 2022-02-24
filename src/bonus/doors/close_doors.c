/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:34:00 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/24 16:34:00 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_doors(t_map *map, t_vector *v, t_doors *doors)
{
	int	len_x;
	int	len_y;

	len_x = doors->x - v->x;
	len_y = doors->y - v->y;
	if (doors->door_open == TRUE
		&& (len_x > 1 || len_x < -1 || len_y > 1 || len_y < -1))
	{
		map->map[doors->y][doors->x] = '2';
		doors->door_open = FALSE;
	}
	return (SUCCESS);
}
