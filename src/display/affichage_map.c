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
#define	RED_PIXEL 0xFF0000

int	affichage_and_creation_sprites(t_data *data)
{
	create_sprites(data);
	affichage_sprites_screen(data);
	return (0);
}

void	affichage_sprites_screen(t_data *data)
{
	data->x = 0;
	while (data->map_lst->map[data->x])
	{
		data->y = 0;
		while (data->map_lst->map[data->x][data->y])
		{
			affichage_sprites_screen2(data);
			data->y++;
		}
		data->x++;
	}
}

void	affichage_sprites_screen2(t_data *data)
{
	int i;
	i = 0;
	if (data->map_lst->map[data->x][data->y] == '1')
		mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr,data->sprites->wall, 64 *data->y, 64 *data->x);
	// else if (data->map[data->x][data->y] == '0')
	// 	// mlx_put_image_to_window(data->mlx_ptr,
	// 	// data->win_ptr,data->sprites->floor, 64 *data->y, 64 *data->x);
	else if (data->map_lst->map[data->x][data->y] == 'P')
	{
		while(i < 10)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, 64 *data->y, 64 *data->x, RED_PIXEL);
			i++;
		}
	}
}
