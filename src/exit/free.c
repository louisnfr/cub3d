/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:49:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/27 16:24:02 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprites(t_data *data, t_sprites *sprites)
{
	(void) data;
	(void) sprites;

	clean_free(&sprites->wall_no.path_face);
	clean_free(&sprites->wall_no.path_img);
	clean_free(&sprites->wall_so.path_face);
	clean_free(&sprites->wall_so.path_img);
	clean_free(&sprites->wall_we.path_face);
	clean_free(&sprites->wall_we.path_img);
	clean_free(&sprites->wall_ea.path_face);
	clean_free(&sprites->wall_ea.path_img);
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
	free_double_str(data->map_info->file_cub);
	free_sprites(data, data->sprites);
	if (data->sprites)
		free(data->sprites);
	if (data->map_info)
		free(data->map_info);
	if (data->mlx->ptr)
	{
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
		mlx_destroy_window(data->mlx->ptr, data->mlx->win);
		mlx_destroy_display(data->mlx->ptr);
		free(data->mlx->ptr);
		if (data->mlx)
			free(data->mlx);
	}
	if (data)
		free(data);
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
