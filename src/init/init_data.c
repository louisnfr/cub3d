/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:37:03 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/03 18:02:20 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIN_W, WIN_H, "cub3d");
	mlx->img = mlx_new_image(mlx->ptr, WIN_W, WIN_H);
	mlx->buf1 = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->length, &mlx->endian);
	return (mlx);
}

static void	set_player_dir(t_player *player, t_data *data)
{
	if (data->map_info->init_position == 'N')
	{
		player->vector.dz = 0;

		player->vector.dx = 0;
		player->vector.dy = -1;
		player->camera.px = 0.66;
		player->camera.py = 0;
	}
	if (data->map_info->init_position == 'S')
	{
		player->vector.dz = 0;

		player->vector.dx = 0;
		player->vector.dy = 1;
		player->camera.px = 0.66;
		player->camera.py = 0;
	}
	if (data->map_info->init_position == 'E')
	{
		player->vector.dz = 0;

		player->vector.dx = 0;
		player->vector.dy = 1;
		player->camera.px = 0.66;
		player->camera.py = 0;
	}
	if (data->map_info->init_position == 'W')
	{
		player->vector.dz = 0;

		player->vector.dx = 0;
		player->vector.dy = 1;
		player->camera.px = 0.66;
		player->camera.py = 0;
	}
}

t_player	*init_player(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->vector.x = data->map_info->x_init;
	player->vector.y = data->map_info->y_init;
	player->vector.z = 0;
	// get orientation with N W E S
	set_player_dir(player, data);
	return (player);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->sprites = malloc(sizeof(t_sprites));
	data->map_info = malloc(sizeof(t_map));
	if (!data || !data->sprites || !data->map_info)
		return (NULL);
	data->move = init_move();
	return (data);
}
