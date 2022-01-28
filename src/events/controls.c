/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:25 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/28 18:48:31 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press(int key, void *param)
{
	t_data	*data;
	double	speed = 0.1;

	data = param;
	printf("key: %d\n", key);
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key == W)
		data->player_x -= speed;
	if (key == S)
		data->player_x += speed;
	if (key == A)
		data->player_y -= speed;
	if (key == D)
		data->player_y += speed;
	if (key == E)
		data->player_dirx += speed;
	if (key == Q)
		data->player_dirx -= speed;
	if (key == LEFT)
		data->player_diry += speed;
	if (key == RIGHT)
		data->player_diry -= speed;
	if (key == UP)
		data->player_dirz += speed;
	if (key == DOWN)
		data->player_dirz -= speed;
	// if (key == LEFT || key <= UP || key <= RIGHT || key <= DOWN)
	// 	move(key, data->player, data);
	return (0);
}

static int	mouse_press(int key, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = param;
	printf("%d\n", key);
	if (key == 1)
	{
	// 	printf("check\n");
		data->mouse->lb_is_pressed = TRUE;
	}
	// if (key == 2)
	// 	data->mouse->rb_is_pressed = TRUE;
	return (0);
}

static int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = param;
	data->mouse->previous_x = data->mouse->x;
	data->mouse->previous_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	t_point ptA;
	t_point ptB;
	ptA.x = data->player_x;
	ptA.y = data->player_y;
	ptB.x = data->mouse->x;
	ptB.y = data->mouse->y;

	// printf("x: %d, y: %d\n", data->mouse->x, data->mouse->y);
	return (SUCCESS);
}

int	exit_all(t_data *data)
{
	(void)data;
	exit(1);
	return (1);
}

void	init_controls(t_data *data)
{
	data->mouse = malloc(sizeof(t_mouse));
	init_mouse(data->mouse);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx->win, 4, 1L << 2, mouse_press, data);
	// mlx_hook(data->mlx->win, 5, 1L << 3, mouse_release, data);
	mlx_hook(data->mlx->win, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->mlx->win, 33, 1L << 2, exit_all, data); //appuie sur la croix
}
