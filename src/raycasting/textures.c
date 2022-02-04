/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:07:00 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/04 16:48:04 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	set_wall_dir(t_tex *tex, t_ray *ray)
// {
// 	if (ray->side == 0 && ray->dirx < 0)
// 		tex->wall_dir = NO;
// 	if (ray->side == 0 && ray->dirx >= 0)
// 		tex->wall_dir = SO;
// 	if (ray->side == 1 && ray->diry < 0)
// 		tex->wall_dir = EA;
// 	if (ray->side == 1 && ray->diry >= 0)
// 		tex->wall_dir = WE;
// }


void	set_texture(t_ray *ray, t_tex *t, int x, t_data *data, int **texture)
{

	double	step;
	double	tex_pos;
	int		color;
	int		tex_y;
	int		y;

	double wall_x; //where exactly the wall was hit
	if (ray->side == 0)
		wall_x = data->player->vector.y + ray->pw * ray->diry;
	else
		wall_x = data->player->vector.x + ray->pw * ray->dirx;
	wall_x -= floor((wall_x));

	int tex_x = (int)wall_x * (double)TEX_W;
	if(ray->side == 0 && ray->dirx > 0) tex_x = TEX_W - tex_x - 1;
	if(ray->side == 1 && ray->diry < 0) tex_x = TEX_W - tex_x - 1;

	step = 1.0 * TEX_H / t->line_height;
	tex_pos = (t->start - WIN_H * 0.5 + t->line_height * 0.5) * step;
	y = t->start - 1;
	while (++y < t->end)
	{
		tex_y = (int)tex_pos & (TEX_H - 1);
		tex_pos += step;
		color = texture[0][TEX_H * tex_y * tex_x];
		// color = GREEN;
		// printf("check %d\n", color);
		put_pixel(x, y, color, data->mlx);
	}
}
