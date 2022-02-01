/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:00:53 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/01 16:40:17 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_vector *vect, char **map, t_data *data)
{
	double	speed;
	double	x;
	double	y;

	if (data->move->shift)
		speed = 0.2;
	else
		speed = 0.1;
	x = vect->x + vect->dx * speed;
	y = vect->y + vect->dy * speed;
	if (map[(int)vect->y][(int)x] != '1')
		vect->x += vect->dx * speed;
	if (map[(int)y][(int)vect->x] != '1')
		vect->y += vect->dy * speed;
}

static void	move_backward(t_vector *vect, char **map)
{
	double	speed;
	double	x;
	double	y;

	speed = 0.1;
	x = vect->x - vect->dx * speed;
	y = vect->y - vect->dy * speed;
	if (map[(int)vect->y][(int)x] != '1')
		vect->x -= vect->dx * speed;
	if (map[(int)y][(int)vect->x] != '1')
		vect->y -= vect->dy * speed;
}

static void	move_left(t_vector *vect, char **map)
{
	double	speed;
	double	x;
	double	y;

	speed = 0.05;
	x = vect->x - vect->dy * speed;
	y = vect->y + vect->dx * speed;
	if (map[(int)vect->y][(int)x] != '1')
		vect->x -= vect->dy * speed;
	if (map[(int)y][(int)vect->x] != '1')
		vect->y += vect->dx * speed;
}

static void	move_right(t_vector *vect, char **map)
{
	double	speed;
	double	x;
	double	y;

	speed = 0.05;
	x = vect->x + vect->dy * speed;
	y = vect->y - vect->dx * speed;
	if (map[(int)vect->y][(int)x] != '1')
		vect->x += vect->dy * speed;
	if (map[(int)y][(int)vect->x] != '1')
		vect->y -= vect->dx * speed;
}

void	move_player(t_data *data)
{
	if (data->move->x)
		move_forward(&data->player->vector, data->map_info->map, data);
	if (data->move->y)
		move_backward(&data->player->vector, data->map_info->map);
	if (data->move->lateral_x)
		move_left(&data->player->vector, data->map_info->map);
	if (data->move->lateral_y)
		move_right(&data->player->vector, data->map_info->map);
}
