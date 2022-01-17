/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:38:21 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 14:42:09 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_sprites(t_data *data)
{
	int	img_width;
	int	img_height;

	// data->sprites->floor = mlx_xpm_file_to_image(data->mlx_ptr,
	// 		"./Image_xpm/Floor.xpm", &img_width, &img_height);
	data->sprites->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./Image_xpm/Wall.xpm", &img_width, &img_height);
}
