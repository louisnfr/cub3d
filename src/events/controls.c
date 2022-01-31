/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:25 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/31 22:02:28 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press(int key, void *param)
{
	t_data	*data;

	data = param;
	printf("key: %d\n", key);
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key == W || key == A || key == S || key == D)
		move_player(key, data->player, data);
	if (key == UP || key == LEFT || key == RIGHT || key == DOWN)
		orient_player(key, &data->player->camera, &data->player->vector);
	return (0);
}

static int	key_release(int key, void *param)
{
	t_data	*data;

	data = param;
	printf("key: %d\n", key);
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key == W || key == A || key == S || key == D)
		move_player(key, data->player, data);
	if (key == UP || key == LEFT || key == RIGHT || key == DOWN)
		orient_player(key, &data->player->camera, &data->player->vector);
	return (0);
}

static int	mouse_press(int key, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = param;
	printf("%d\n", key);
	// if (key == LEFT_MB)
	// 	data->mouse->lb_is_pressed = TRUE;
	// if (key == RIGHT_MB)
	// 	data->mouse->rb_is_pressed = TRUE;
	return (0);
}

static int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = param;
	data->mouse->old_x = data->mouse->x;
	data->mouse->old_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	return (SUCCESS);
}

static int	exit_all(t_data *data)
{
	free_data(data);
	exit(1);
	return (1);
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
