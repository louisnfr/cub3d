/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:57:59 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/23 18:14:31 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	if_checks_one(t_tex *tex, t_ray *ray, t_data *data)
{
	if (ray->side == 0 && ray->dirx < 0
		&& data->map_info->map[ray->mapy][ray->mapx] != '2'
		&& data->map_info->map[ray->mapy][ray->mapx] != '3')
		tex->wall_dir = 0;
	if (ray->side == 0 && ray->dirx >= 0
		&& data->map_info->map[ray->mapy][ray->mapx] != '2'
		&& data->map_info->map[ray->mapy][ray->mapx] != '3')
		tex->wall_dir = 1;
	if (ray->side == 1 && ray->diry < 0
		&& data->map_info->map[ray->mapy][ray->mapx] != '2'
		&& data->map_info->map[ray->mapy][ray->mapx] != '3')
		tex->wall_dir = 2;
}

void	if_checks_two(t_tex *tex, t_ray *ray, t_data *data)
{
	if (ray->side == 1 && ray->diry >= 0
		&& data->map_info->map[ray->mapy][ray->mapx] != '2'
		&& data->map_info->map[ray->mapy][ray->mapx] != '3')
		tex->wall_dir = 3;
	if (data->map_info->map[ray->mapy][ray->mapx] == '2'
		&& data->map_info->map[ray->mapy][ray->mapx] != '3')
		tex->wall_dir = 4;
	if (data->map_info->map[ray->mapy][ray->mapx] == '3')
		tex->wall_dir = 5;
}

int	get_color(t_tex *t, t_data *data, int tex_x, int tex_y)
{
	int	color;

	if (t->wall_dir == 0)
		color = data->textures->wall_we.tex[TEX_H * tex_y + tex_x];
	if (t->wall_dir == 1)
		color = data->textures->wall_ea.tex[TEX_H * tex_y + tex_x];
	if (t->wall_dir == 2)
		color = data->textures->wall_no.tex[TEX_H * tex_y + tex_x];
	if (t->wall_dir == 3)
		color = data->textures->wall_so.tex[TEX_H * tex_y + tex_x];
	if (t->wall_dir == 4)
	{
		color = data->textures->doors.tex[TEX_H * tex_y + tex_x];
		color = (color >> 1) & 8355711;
	}
	if (t->wall_dir == 5)
	{
		color = data->textures->doors_open.tex[TEX_H * tex_y + tex_x];
		color = (color >> 1) & 8355711;
	}
	return (color);
}
