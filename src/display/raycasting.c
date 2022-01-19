/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:31:04 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 15:56:30 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		draw_map(t_data *data)
{
	int bpp;
	int sol;
	int endian;

	// init mlx
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3d\n");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = (int *)mlx_get_data_addr(data->img_ptr, &bpp, &sol, &endian);

	double posX = 22, posY = 12;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;
	double time = 0;
	double old_time = 0;

	while (!done())
	{
		for(int x = 0; x < WIDTH; x++)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / (double)WIDTH - 1; //x-coordinate in camera space
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;
		}
	}
	// init_controls(data);

	// create_and_display_sprites(data);
	// mlx_hook(data->win_ptr, 12, 1L << 15, create_and_display_sprites, data);
	// mlx_hook(data->win_ptr, 2, 1L << 0, handle_keypress, data);
	// mlx_hook(data->win_ptr, 17, 0, free_all_functions, data);
	mlx_loop(data->mlx_ptr);
	// free(data->mlx_ptr);
	return (0);
}
