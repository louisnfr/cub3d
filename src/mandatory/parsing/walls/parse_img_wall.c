/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:22 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/23 18:30:34 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	add_face_wall_we_to_mlx(t_data *data, char *path_img)
{
	data->textures->wall_we.img = mlx_xpm_file_to_image(data->mlx->ptr,
			path_img, &data->textures->wall_we.width,
			&data->textures->wall_we.height);
	if (!data->textures->wall_we.img)
		ft_exit_parsing(data, WALLS_WRONG_IMG);
	return (FAILURE);
}

static int	add_face_wall_ea_to_mlx(t_data *data, char *path_img)
{
	data->textures->wall_ea.img = mlx_xpm_file_to_image(data->mlx->ptr,
			path_img, &data->textures->wall_ea.width,
			&data->textures->wall_ea.height);
	if (!data->textures->wall_ea.img)
		ft_exit_parsing(data, WALLS_WRONG_IMG);
	return (FAILURE);
}

static	int	add_face_wall_so_to_mlx(t_data *data, char *path_img)
{
	data->textures->wall_so.img = mlx_xpm_file_to_image(data->mlx->ptr,
			path_img, &data->textures->wall_so.width,
			&data->textures->wall_so.height);
	if (!data->textures->wall_so.img)
		ft_exit_parsing(data, WALLS_WRONG_IMG);
	return (FAILURE);
}

static	int	add_face_wall_no_to_mlx(t_data *data, char *path_img)
{
	data->textures->wall_no.img
		= mlx_xpm_file_to_image(data->mlx->ptr, path_img,
			&data->textures->wall_no.width, &data->textures->wall_no.height);
	if (!data->textures->wall_no.img)
		ft_exit_parsing(data, WALLS_WRONG_IMG);
	return (FAILURE);
}

int	add_img_wall_to_mlx(t_data *data)
{
	if (!ft_strcmp (data->textures->wall_no.path_face, "NO"))
		add_face_wall_no_to_mlx(data, data->textures->wall_no.path_img);
	if (!ft_strcmp (data->textures->wall_so.path_face, "SO"))
		add_face_wall_so_to_mlx(data, data->textures->wall_so.path_img);
	if (!ft_strcmp (data->textures->wall_ea.path_face, "EA"))
		add_face_wall_ea_to_mlx(data, data->textures->wall_ea.path_img);
	if (!ft_strcmp (data->textures->wall_we.path_face, "WE"))
		add_face_wall_we_to_mlx(data, data->textures->wall_we.path_img);
	return (FAILURE);
}
