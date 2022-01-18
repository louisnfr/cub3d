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
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3d\n");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		return (MLX_ERROR);
	}
	init_controls(data);
	mlx_hook(data->win_ptr, 12, 1L << 15, create_and_display_sprites, data);
	// mlx_hook(data->win_ptr, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, free_all_functions, data);
	mlx_loop(data->mlx_ptr);
	// free(data->mlx_ptr);
	return (0);
}
