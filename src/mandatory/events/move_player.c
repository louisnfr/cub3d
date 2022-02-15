/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:00:53 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/15 14:32:40 by lraffin          ###   ########.fr       */
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
	x = vect->x + vect->dx * speed * 2;
	y = vect->y + vect->dy * speed * 2;
	if (map[(int)x][(int)vect->y] == '0')
		vect->x += vect->dx * speed;
	if (map[(int)vect->x][(int)y] == '0')
		vect->y += vect->dy * speed;
}

static void	move_backward(t_vector *vect, char **map)
{
	double	speed;
	double	x;
	double	y;

	speed = 0.1;
	x = vect->x - vect->dx * speed * 2;
	y = vect->y - vect->dy * speed * 2;
	if (map[(int)x][(int)vect->y] == '0')
		vect->x -= vect->dx * speed;
	if (map[(int)vect->x][(int)y] == '0')
		vect->y -= vect->dy * speed;
}

static void	move_left(t_vector *vect, char **map)
{
	double	speed;
	double	x;
	double	y;

	speed = 0.1;
	x = vect->x - vect->dy * speed;
	y = vect->y + vect->dx * speed;
	printf("map[%d][%d] : '%c'\n", (int)vect->y, (int)x,map[(int)vect->y][(int)x]);
	if (map[(int)x][(int)vect->y] == '0')
		vect->x -= vect->dy * speed;
	if (map[(int)vect->x][(int)y] == '0')
		vect->y += vect->dx * speed;
}

static void	move_right(t_vector *vect, char **map)
{
	double	speed;
	double	x;
	double	y;

	speed = 0.1;
	x = vect->x + vect->dy * speed;
	y = vect->y - vect->dx * speed;
	if (map[(int)x][(int)vect->y] == '0')
		vect->x -= vect->dy * speed;
	if (map[(int)vect->x][(int)y] == '0')
		vect->y += vect->dx * speed;
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
