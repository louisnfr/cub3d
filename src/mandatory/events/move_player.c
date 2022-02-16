/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:00:53 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/16 14:17:16 by vbachele         ###   ########.fr       */
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
	x = vect->x + vect->dx * speed * 3;
	y = vect->y + vect->dy * speed * 3;
	if (map[(int)y][(int)vect->x] != '1')
		vect->y += vect->dy * speed;
	if (map[(int)vect->y][(int)x] != '1')
		vect->x += vect->dx * speed;
	sprites_move(data, 1, vect); // bonus
}

static void	move_backward(t_vector *vect, char **map, t_data *data)
{
	double	speed;
	double	x;
	double	y;

	speed = 0.1;
	x = vect->x - vect->dx * speed * 3;
	y = vect->y - vect->dy * speed * 3;

	if (map[(int)vect->y][(int)x] != '1')
		vect->x -= vect->dx * speed;
	if (map[(int)y][(int)vect->x] != '1')
		vect->y -= vect->dy * speed;
	sprites_move(data, 2, vect); // bonus
	//sprites_move(data, 2, vect);
}

static void	move_left(t_vector *vect, char **map, t_data *data)
{
	double	speed;
	double	x;
	double	y;

	speed = 0.1;
	x = vect->x - vect->dy * speed * -2;
	y = vect->y + vect->dx * speed * -2;
	if (map[(int)y][(int)vect->x] != '1')
		vect->y -= vect->dx * speed;
	if (map[(int)vect->y][(int)x] != '1')
		vect->x += vect->dy * speed;
	sprites_move(data, 1, vect); // bonus
}

static void	move_right(t_vector *vect, char **map, t_data *data)
{
	double	speed;
	double	x;
	double	y;

	speed = 0.1;
	x = vect->x + vect->dy * speed * -2;
	y = vect->y - vect->dx * speed * -2;
	if (map[(int)y][(int)vect->x] != '1')
		vect->y += vect->dx * speed;
	if (map[(int)vect->y][(int)x] != '1')
		vect->x -= vect->dy * speed;
	sprites_move(data, 1, vect); // bonus
}

void	move_player(t_data *data)
{
	if (data->move->x)
		move_forward(&data->player->vector, data->map_info->map, data);
	if (data->move->y)
		move_backward(&data->player->vector, data->map_info->map, data);
	if (data->move->lateral_x)
		move_left(&data->player->vector, data->map_info->map, data);
	if (data->move->lateral_y)
		move_right(&data->player->vector, data->map_info->map, data);
}
