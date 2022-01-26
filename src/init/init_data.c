/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:37:03 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/26 15:30:14 by vbachele         ###   ########.fr       */
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
	data->map_info = malloc(sizeof(t_map));
	if (!data || !data->sprites || !data->map_info)
		return (NULL);
	init_values(data);
	data->mlx = init_mlx();
	return (data);
}
