/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:07:00 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/21 13:38:51 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check where the camera if facing to print the right color

static void	set_wall_dir(t_tex *tex, t_ray *ray, t_data *data)
{
	(void) data;
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map_info->map[i])
	{
		while (data->map_info->map[i][j])
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
			if (ray->side == 1 && ray->diry >= 0
				&& data->map_info->map[ray->mapy][ray->mapx] != '2'
				&& data->map_info->map[ray->mapy][ray->mapx] != '3')
				tex->wall_dir = 3;
			if (data->map_info->map[ray->mapy][ray->mapx] == '2'
				&& data->map_info->map[ray->mapy][ray->mapx] != '3')
				tex->wall_dir = 4;
			if (data->map_info->map[ray->mapy][ray->mapx] == '3')
				tex->wall_dir = 5;
			j++;
		}
		i++;
	}
}

static	int	define_tex_x(int tex_x, t_ray *ray, double wall_x)
{
	tex_x = (int)(wall_x * (double)TEX_W);
	if (ray->side == 0 && ray->dirx > 0)
		tex_x = TEX_W - tex_x - 1;
	if (ray->side == 1 && ray->diry < 0)
		tex_x = TEX_W - tex_x - 1;
	return (tex_x);
}

static	double	define_wall_x(t_ray *ray, t_data *data, double wall_x)
{
	if (ray->side == 0)
		wall_x = data->player->vector.y + ray->pw * ray->diry;
	else
		wall_x = data->player->vector.x + ray->pw * ray->dirx;
	wall_x -= floor((wall_x));
	return (wall_x);
}

static	void	print_walls(t_tex *t, t_data *data, int x, int tex_x)
{
	int		y;
	double	tex_pos;
	double	step;
	int		tex_y;
	int		color;

	y = t->start - 1;
	step = 1.0 * TEX_H / t->line_height;
	tex_pos = (t->start - WIN_H * 0.5 + t->line_height * 0.5) * step;
	while (++y < t->end)
	{
		tex_y = (int)tex_pos & (TEX_H - 1);
		tex_pos += step;
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
		put_pixel(x, y, color, data->mlx);
	}
}

void	draw_texture(t_ray *ray, t_tex *t, int x, t_data *data)
{
	double	wall_x;
	int		tex_x;

	wall_x = 0;
	tex_x = 0;
	set_wall_dir(t, ray, data);
	wall_x = define_wall_x(ray, data, wall_x);
	tex_x = define_tex_x(tex_x, ray, wall_x);;
	print_walls(t, data, x, tex_x);
}
