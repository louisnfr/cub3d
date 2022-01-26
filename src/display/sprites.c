/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:26:56 by vbachele          #+#    #+#             */
/*   Updated: 2021/09/04 21:52:36:34 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_and_display_sprites(t_data *data)
{
	create_sprites(data);
	display_sprites(data);
	return (0);
}

void	display_sprites(t_data *data)
{
	data->x = 0;
	while (data->map->tab[data->x])
	{
		data->y = 0;
		while (data->map->tab[data->x][data->y])
		{
			display_sprites2(data);
			data->y++;
		}
		data->x++;
	}
}

void	display_sprites2(t_data *data)
{
	int i;

	i = 0;
	if (data->map->tab[data->x][data->y] == '1')
		mlx_put_image_to_window(data->mlx->ptr,
		data->mlx->win, data->sprites->wall, 64 * data->y, 64 * data->x);
	// else if (data->map[data->x][data->y] == '0')
	// 	// mlx_put_image_to_window(data->mlx_ptr,
	// 	// data->win,data->sprites->floor, 64 *data->y, 64 *data->x);
	else if (data->map->tab[data->x][data->y] == 'P')
	{
		data->player_x = data->y * 64;
		data->player_y = data->x * 64;
		mlx_pixel_put(data->mlx->ptr, data->mlx->win, 64 * data->y, 64 * data->x, RED);
	}
}
