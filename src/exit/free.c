/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:49:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/26 15:42:46 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprites(t_data *data, t_sprites *sprites)
{
	if (sprites->wall_ea.img)
		mlx_destroy_image(data->mlx->ptr, sprites->wall_ea.img);
	if (sprites->wall_no.img)
		mlx_destroy_image(data->mlx->ptr, sprites->wall_no.img);
	if (sprites->wall_so.img)
		mlx_destroy_image(data->mlx->ptr, sprites->wall_so.img);
	if (sprites->wall_we.img)
		mlx_destroy_image(data->mlx->ptr, sprites->wall_we.img);
}

int	free_data(t_data *data)
{
 	free_double_str(data->map_info->map);
	free_sprites(data, data->sprites);
	free(data->sprites);
	free(data->map_info);
	// mlx_destroy_display(data->mlx->ptr);
	free(data->mlx->ptr);
	free(data);
	mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	return (EXIT_SUCCESS);
}

int	free_all_functions(t_data *data)
{
	if (data->sprites)
		free(data->sprites);
	// if (data->map_info)
	// 	ft_lstclear(&data->map_info, del_content);
	free_double_tableau(data);
	mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	if (data)
		free(data);
	free(data->mlx->ptr);
	exit(1);
}

void	free_double_tableau(t_data *data)
{
	int	i;

	i = -1;
	while (data->map_info->map[++i])
		free(data->map_info->map[i]);
	free(data->map_info->map);
}
