/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:49:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/09 14:34:21 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_color_file(t_color color)
{
	clean_free(&color.raw);
}

void	free_sprites(t_data *data, t_textures *textures)
{
	clean_free(&textures->wall_no.path_face);
	clean_free(&textures->wall_no.path_img);
	free(textures->wall_no.tex);
	clean_free(&textures->wall_so.path_face);
	clean_free(&textures->wall_so.path_img);
	free(textures->wall_so.tex);
	clean_free(&textures->wall_we.path_face);
	clean_free(&textures->wall_we.path_img);
	free(textures->wall_we.tex);
	clean_free(&textures->wall_ea.path_face);
	clean_free(&textures->wall_ea.path_img);
	free(textures->wall_ea.tex);
	if (textures->wall_ea.img)
		mlx_destroy_image(data->mlx->ptr, textures->wall_ea.img);
	if (textures->wall_no.img)
		mlx_destroy_image(data->mlx->ptr, textures->wall_no.img);
	if (textures->wall_so.img)
		mlx_destroy_image(data->mlx->ptr, textures->wall_so.img);
	if (textures->wall_we.img)
		mlx_destroy_image(data->mlx->ptr, textures->wall_we.img);
}

static void	free_all_structs(t_data *data)
{
	if (data->sprites)
		free(data->sprites);
	if (data->map_info)
		free(data->map_info);
	if (data->move)
		free(data->move);
	if (data->mouse)
		free(data->mouse);
	if (data->player)
		free(data->player);
	if (data->textures)
		free(data->textures);
	if (data->mlx)
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
}

int	free_data(t_data *data)
{
	free_double_str(data->map_info->map);
	free_double_str(data->map_info->file_cub);
	free_sprites(data, data->textures);
	free_color_file(data->textures->ceiling_color);
	free_color_file(data->textures->floor_color);
	free_all_structs(data);
	return (FAILURE);
}
