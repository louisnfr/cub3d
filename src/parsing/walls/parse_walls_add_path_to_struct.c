/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls_add_path_to_struct.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:38 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/23 18:30:38 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	strdup_struct_walls(t_data *data,
				char *face_wall, char *path, int i)
{
	if (data->textures->check[0] < 1 && i == 0)
	{
		data->textures->wall_no.path_face = ft_strdup(face_wall);
		data->textures->wall_no.path_img = ft_strdup(path);
	}
	if (data->textures->check[1] < 1 && i == 1)
	{
		data->textures->wall_so.path_face = ft_strdup(face_wall);
		data->textures->wall_so.path_img = ft_strdup(path);
	}
	if (data->textures->check[2] < 1 && i == 2)
	{
		data->textures->wall_we.path_face = ft_strdup(face_wall);
		data->textures->wall_we.path_img = ft_strdup(path);
	}
	if (data->textures->check[3] < 1 && i == 3)
	{
		data->textures->wall_ea.path_face = ft_strdup(face_wall);
		data->textures->wall_ea.path_img = ft_strdup(path);
	}
}

static void	check_struct_walls(t_data *data, char *face_wall, char *path)
{
	if (!ft_strcmp("NO", face_wall))
		strdup_struct_walls(data, face_wall, path, 0);
	else if (!ft_strcmp("SO", face_wall))
		strdup_struct_walls(data, face_wall, path, 1);
	else if (!ft_strcmp("WE", face_wall))
		strdup_struct_walls(data, face_wall, path, 2);
	else if (!ft_strcmp("EA", face_wall))
		strdup_struct_walls(data, face_wall, path, 3);
}

int	check_and_add_path_walls(t_data *data, int i, char *face_wall)
{
	char	**img;

	img = ft_split_charset(data->map_info->file_cub[i], " \t");
	if (!img[1] || img[2])
	{
		free_double_str(img);
		ft_exit_parsing(data, WALLS_WRONG_ARGUMENTS);
	}
	check_struct_walls(data, face_wall, img[1]);
	free_double_str(img);
	return (FAILURE);
}
