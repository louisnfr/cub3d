/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:25 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/28 17:37:58 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press(int key, t_data *data)
{
	// printf("pressed: %d\n", key);
	if (key == W)
		data->move->x = TRUE;
	if (key == S)
		data->move->y = TRUE;
	if (key == A)
		data->move->lateral_x = TRUE;
	if (key == D)
		data->move->lateral_y = TRUE;
	if (key == RIGHT)
		data->move->dirx = TRUE;
	if (key == LEFT)
		data->move->diry = TRUE;
	if (key == SHIFT)
		data->move->shift = TRUE;
	if (key == M)
		data->move->minimap = TRUE; // bonus
	return (SUCCESS);
}

static int	key_release(int key, t_data *data)
{
	// printf("released: %d\n", key);
	if (key == ESC)
		exit_all(data);
	if (key == W)
		data->move->x = FALSE;
	if (key == S)
		data->move->y = FALSE;
	if (key == A)
		data->move->lateral_x = FALSE;
	if (key == D)
		data->move->lateral_y = FALSE;
	if (key == RIGHT)
		data->move->dirx = FALSE;
	if (key == LEFT)
		data->move->diry = FALSE;
	if (key == SHIFT)
		data->move->shift = FALSE;
	if (key == M)
		data->move->minimap = FALSE; // bonus
	return (SUCCESS);
}

/*** For the bonus
***/

static int	mouse_press(int key, int x, int y, t_data *data)
{
	(void)data;
	(void)x;
	(void)y;
	if (key == LEFT_MB)
	{
		data->move->attack = TRUE;
	}
	printf("clicked: %d\n", key);
	return (SUCCESS);
}

/*** For the bonus
***/

static int	mouse_release(int key, int x, int y, t_data *data)
{
	(void)data;
	(void)x;
	(void)y;
	if (key == LEFT_MB && data->sprites->ennemy.darth_vader == TRUE)
	{
		//usleep(800000);
		data->move->attack = FALSE; // bonus
	}
	else if (key == LEFT_MB && data->sprites->ennemy.stormtrooper == TRUE)
	{
		//usleep(250000);
		data->move->attack = FALSE; // bonus
	}
	else
	{
		data->move->attack = FALSE;
	}

	return (SUCCESS);
}


static int	mouse_move(int x, int y, t_data *data)
{
	double	dir;
	double	plane;
	double	speed;

	speed = 0.03;
	data->mouse->old_x = data->mouse->x;
	data->mouse->x = x;
	if (data->mouse->old_x < data->mouse->x && -data->mouse->old_x + data->mouse->x > 10)
	{
		dir = data->player->vector.dx;
		data->player->vector.dx = data->player->vector.dx
		* cos(speed) - data->player->vector.dy * sin(speed);
		data->player->vector.dy = dir * sin(speed)
		+ data->player->vector.dy * cos(speed);
		plane = data->player->camera.px;
		data->player->camera.px = data->player->camera.px
		* cos (speed) - data->player->camera.py * sin(speed);
		data->player->camera.py = plane * sin(speed)
		+ data->player->camera.py * cos(speed);
	}
	if (data->mouse->old_x > data->mouse->x && data->mouse->old_x - data->mouse->x > 10)
	{
		dir = data->player->vector.dx;
		data->player->vector.dx = data->player->vector.dx
		* cos(-speed) - data->player->vector.dy * sin(-speed);
		data->player->vector.dy = dir * sin(-speed)
		+ data->player->vector.dy * cos(-speed);
		plane = data->player->camera.px;
		data->player->camera.px = data->player->camera.px
		* cos(-speed) - data->player->camera.py * sin(-speed);
		data->player->camera.py = plane * sin(-speed)
		+ data->player->camera.py * cos(-speed);
	}
	mlx_mouse_move(data->mlx->ptr, data->mlx->win, (int)(WIN_W / 2), y);
	return (SUCCESS);
}


void	init_controls(t_data *data)
{
	data->move->minimap = FALSE;
	data->mouse = malloc(sizeof(t_mouse));
	init_mouse(data->mouse);
	mlx_mouse_hide(data->mlx->ptr, data->mlx->win);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx->win, 4, 1L << 2, mouse_press, data); // bonus
	mlx_hook(data->mlx->win, 5, 1L << 3, mouse_release, data);
	//mlx_hook(data->mlx->win, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->mlx->win, 33, 1L << 2, exit_all, data);
}
