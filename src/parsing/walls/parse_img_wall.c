/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:22 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/04 12:09:21 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	add_face_wall_we_to_mlx(t_data *data, char *path_img)
{
	data->sprites->wall_we.img = mlx_xpm_file_to_image(data->mlx->ptr,
			path_img, &data->sprites->wall_we.width,
			&data->sprites->wall_we.height);
	if (!data->sprites->wall_we.img)
		ft_exit_parsing(data, ERROR_WALLS_WRONG_IMG);
	return (FAILURE);
}

static int	add_face_wall_ea_to_mlx(t_data *data, char *path_img)
{
	data->sprites->wall_ea.img = mlx_xpm_file_to_image(data->mlx->ptr,
			path_img, &data->sprites->wall_ea.width,
			&data->sprites->wall_ea.height);
	if (!data->sprites->wall_ea.img)
		ft_exit_parsing(data, ERROR_WALLS_WRONG_IMG);
	return (FAILURE);
}

static	int	add_face_wall_so_to_mlx(t_data *data, char *path_img)
{
	data->sprites->wall_so.img = mlx_xpm_file_to_image(data->mlx->ptr,
			path_img, &data->sprites->wall_so.width,
			&data->sprites->wall_so.height);
	if (!data->sprites->wall_so.img)
		ft_exit_parsing(data, ERROR_WALLS_WRONG_IMG);
	return (FAILURE);
}

static	int	add_face_wall_no_to_mlx(t_data *data, char *path_img)
{
	data->sprites->wall_no.img
		= mlx_xpm_file_to_image(data->mlx->ptr, path_img,
			&data->sprites->wall_no.width, &data->sprites->wall_no.height);
	if (!data->sprites->wall_no.img)
		ft_exit_parsing(data, ERROR_WALLS_WRONG_IMG);
	return (FAILURE);
}

int	add_img_wall_to_mlx(t_data *data)
{
	if (!ft_strcmp (data->sprites->wall_no.path_face, "NO"))
		add_face_wall_no_to_mlx(data, data->sprites->wall_no.path_img);
	if (!ft_strcmp (data->sprites->wall_so.path_face, "SO"))
		add_face_wall_so_to_mlx(data, data->sprites->wall_so.path_img);
	if (!ft_strcmp (data->sprites->wall_ea.path_face, "EA"))
		add_face_wall_ea_to_mlx(data, data->sprites->wall_ea.path_img);
	if (!ft_strcmp (data->sprites->wall_we.path_face, "WE"))
		add_face_wall_we_to_mlx(data, data->sprites->wall_we.path_img);
	return (FAILURE);
}
