/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:25 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/19 16:33:23 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

	printf("x: %d, y: %d\n", data->mouse->x, data->mouse->y);
	// mlx_destroy_display(data->mlx_ptr);
	// create_and_display_sprites(data);
	draw_line(ptA, ptB, data);
	// if (data->mouse->x < WIDTH && data->mouse->y < HEIGHT)
	// {
	// 	draw_line(ptA, ptB, data);
	// 	printf("check11\n");
		// create_and_display_sprites(data);
	// }
	// // printf("check %d\n", mouse->lb_is_pressed);
	// if (mouse->lb_is_pressed)
	// {
	// 	printf("check\n");
	// }
	return (SUCCESS);
}

void	init_controls(t_data *data)
{
	data->mouse = malloc(sizeof(t_mouse));
	init_mouse(data->mouse);
	// mlx_hook(data->win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->win_ptr, 4, 1L << 2, mouse_press, data);
	// mlx_hook(data->win_ptr, 5, 1L << 3, mouse_release, data);
	mlx_hook(data->win_ptr, 6, 1L << 6, mouse_move, data);
}