/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:25 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/28 17:11:56 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press(int key, t_data *data)
{
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
		data->move->minimap = TRUE;
	return (SUCCESS);
}

static int	key_release(int key, t_data *data)
{
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
		data->move->minimap = FALSE;
	return (SUCCESS);
}

static int	mouse_move(int x, int y, t_data *data)
{
	int		diff;
	double	speed;

	(void)y;
	speed = 0.02;
	data->mouse->old_x = data->mouse->x;
	data->mouse->x = x;
	diff = ft_abs(data->mouse->old_x - x);
	if (data->mouse->old_x < data->mouse->x)
		mouse_orient_right(speed, data);
	if (data->mouse->old_x > data->mouse->x)
		mouse_orient_left(speed, data);
	mlx_mouse_move(data->mlx->ptr, data->mlx->win,
		(int)(WIN_W * 0.5), (int)(WIN_H * 0.5));
	return (SUCCESS);
}

void	init_controls(t_data *data)
{
	data->move->minimap = FALSE;
	data->mouse = malloc(sizeof(t_mouse));
	init_mouse(data->mouse);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx->win, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->mlx->win, 33, 1L << 2, exit_all, data);
}
