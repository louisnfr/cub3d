/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:25 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/04 11:54:18 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press(int key, t_data *data)
{
	printf("pressed: %d\n", key);
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
	return (SUCCESS);
}

static int	key_release(int key, t_data *data)
{
	printf("released: %d\n", key);
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
	return (SUCCESS);
}

static int	mouse_press(int key, int x, int y, t_data *data)
{
	(void)data;
	(void)x;
	(void)y;
	printf("clicked: %d\n", key);
	return (SUCCESS);
}

static int	mouse_move(int x, int y, t_data *data)
{
	(void)data;
	data->mouse->old_x = data->mouse->x;
	data->mouse->old_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	return (SUCCESS);
}


void	init_controls(t_data *data)
{
	data->mouse = malloc(sizeof(t_mouse));
	init_mouse(data->mouse);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx->win, 4, 1L << 2, mouse_press, data);
	mlx_hook(data->mlx->win, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->mlx->win, 33, 1L << 2, exit_all, data);
}
