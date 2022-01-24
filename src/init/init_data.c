/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:37:03 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/24 14:28:07 by lraffin          ###   ########.fr       */
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
	data->map_info->width = 0;
	data->map_info->height = 0;
	// data->map_info->next = NULL;
	// data->Ennemy_1_x = 0;
	// data->Ennemy_1_y = 0;
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "cub3d");
	return (mlx);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->sprites = malloc(sizeof(t_sprites));
	data->map_info = malloc(sizeof(t_map));
	if (!data || !data->sprites || !data->map_info)
		return (NULL);
	init_values(data);
	data->mlx = init_mlx();
	return (data);
}
