/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_sprites_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:38:21 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/14 17:25:34 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	creation_sprites(t_root *root)
{
	int	img_width;
	int	img_height;

	// root->sprites->floor = mlx_xpm_file_to_image(root->mlx_ptr,
	// 		"./Image_xpm/Floor.xpm", &img_width, &img_height);
	root->sprites->wall = mlx_xpm_file_to_image(root->mlx_ptr,
			"./Image_xpm/Wall.xpm", &img_width, &img_height);
}
