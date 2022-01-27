/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:37:03 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/27 22:16:04 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_values(t_data *data)
{
	data->i = 0;
	data->x = 0;
	data->y = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->map->w = 0;
	data->map->h = 0;
	// data->map_info->next = NULL;
	// data->Ennemy_1_x = 0;
	// data->Ennemy_1_y = 0;
}

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

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->sprites = malloc(sizeof(t_sprites));
	data->map = malloc(sizeof(t_map));
	if (!data || !data->sprites || !data->map)
		return (NULL);
	init_values(data);
	data->mlx = init_mlx();
	return (data);
}
