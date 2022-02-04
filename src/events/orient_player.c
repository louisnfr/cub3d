/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orient_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:09:29 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/04 17:29:28 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orient_player(t_camera *cam, t_vector *vect, t_data *data)
{
	double	dir;
	double	plane;
	double	speed;

	speed = 0.08;
	if (data->move->dirx)
	{
		dir = vect->dx;
		vect->dx = vect->dx * cos(speed) - vect->dy * sin(speed);
		vect->dy = dir * sin(speed) + vect->dy * cos(speed);
		plane = cam->px;
		cam->px = cam->px * cos (speed) - cam->py * sin(speed);
		cam->py = plane * sin(speed) + cam->py * cos(speed);
	}
	if (data->move->diry)
	{
		dir = vect->dx;
		vect->dx = vect->dx * cos(-speed) - vect->dy * sin(-speed);
		vect->dy = dir * sin(-speed) + vect->dy * cos(-speed);
		plane = cam->px;
		cam->px = cam->px * cos(-speed) - cam->py * sin(-speed);
		cam->py = plane * sin(-speed) + cam->py * cos(-speed);
	}
}
