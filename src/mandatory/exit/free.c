/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:49:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/24 17:21:47 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_str_textures(t_textures *textures)
{
	clean_free(&textures->wall_no.path_face);
	clean_free(&textures->wall_no.path_img);
	clean_free(&textures->wall_so.path_face);
	clean_free(&textures->wall_so.path_img);
	clean_free(&textures->wall_we.path_face);
	clean_free(&textures->wall_we.path_img);
	clean_free(&textures->wall_ea.path_face);
	clean_free(&textures->wall_ea.path_img);
}

static void	free_color_file(t_color color)
{
	clean_free(&color.raw);
}

static void	free_textures(t_data *data, t_textures *textures)
{
	free(textures->wall_no.tex);
	free(textures->wall_so.tex);
	free(textures->wall_we.tex);
	free(textures->wall_ea.tex);
	free(textures->doors.tex);
	free(textures->doors_open.tex);
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
		free(data->mlx);
	}
	if (data)
		free(data);
}

int	free_data(t_data *data)
{
	free_double_str(data->map_info->map);
	free_double_str(data->map_info->file_cub);
	free_str_textures(data->textures);
	free_textures(data, data->textures);
	free_color_file(data->textures->ceiling_color);
	free_color_file(data->textures->floor_color);
	free_all_structs(data);
	return (FAILURE);
}
