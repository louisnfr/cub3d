/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:22 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 14:56:23 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	add_face_wall_we_to_mlx(t_data *data, char *path_img)
{
	data->sprites->wall_we.img = mlx_xpm_file_to_image(data->mlx->ptr,
			path_img, &data->sprites->wall_we.width,
			&data->sprites->wall_we.height);
	if (!data->sprites->wall_we.img)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	add_face_wall_ea_to_mlx(t_data *data, char *path_img)
{
	data->sprites->wall_ea.img = mlx_xpm_file_to_image(data->mlx->ptr,
			path_img, &data->sprites->wall_ea.width,
			&data->sprites->wall_ea.height);
	if (!data->sprites->wall_ea.img)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int	add_face_wall_so_to_mlx(t_data *data, char *path_img)
{
	data->sprites->wall_so.img = mlx_xpm_file_to_image(data->mlx->ptr,
			path_img, &data->sprites->wall_so.width,
			&data->sprites->wall_so.height);
	if (!data->sprites->wall_so.img)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int	add_face_wall_no_to_mlx(t_data *data, char *path_img)
{
	data->sprites->wall_no.img
		= mlx_xpm_file_to_image(data->mlx->ptr, path_img,
			&data->sprites->wall_no.width, &data->sprites->wall_no.height);
	if (!data->sprites->wall_no.img)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	add_img_wall_to_mlx(t_data *data)
{
	if (!ft_strcmp (data->sprites->wall_no.path_face, "NO"))
	{
		if (add_face_wall_no_to_mlx(data, data->sprites->wall_no.path_img))
			return (EXIT_FAILURE);
	}
	if (!ft_strcmp (data->sprites->wall_so.path_face, "SO"))
	{
		if (add_face_wall_so_to_mlx(data, data->sprites->wall_so.path_img))
			return (EXIT_FAILURE);
	}
	if (!ft_strcmp (data->sprites->wall_ea.path_face, "EA"))
	{
		if (add_face_wall_ea_to_mlx(data, data->sprites->wall_ea.path_img))
			return (EXIT_FAILURE);
	}
	if (!ft_strcmp (data->sprites->wall_we.path_face, "WE"))
	{
		if (add_face_wall_we_to_mlx(data, data->sprites->wall_we.path_img))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
