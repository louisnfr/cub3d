/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:26:00 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/24 18:56:41 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		raycasting(t_data *data)
{
	for(int q=0; data->map_info->map[q]; q++)
		printf("data->map_info->map[%d]: %s\n", q, data->map_info->map[q]);
	// data->mlx->img_ptr = mlx_new_image(data->mlx->ptr, WIDTH, HEIGHT);
	// data->mlx->img1 = mlx_get_data_addr(data->mlx->img_ptr, &data->mlx->bpp,
	// 				&data->mlx->length, &data->mlx->endian);
	
	return (0);
}
