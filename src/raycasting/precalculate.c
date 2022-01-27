/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:26:00 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/27 15:44:28 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int		precalculate_rays(t_data *data)
// {
	/*
	int	matrix_z[3][3] = {
		{cos(teta), - sin(teta), 0},
		{sin(teta), cos(teta), 0},
		{0, 0, 1}
	};
	*/
	// t_point	vect;

	// double	fov;
	// double	rh;
	// double	rv;

	// int	i;
	// int	j;

	// fov = FOV * PI / 180;
	// rh = 2 * tan((fov * 0.5)) / WIN_W;
	// rv = 2 * tan(FOV * WIN_H / (WIN_W * 2)) / WIN_H;

	// vect.x = 0;
	// vect.y = -1;
	// vect.z = 0;

	// if (data->mlx->img)
	// 	mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	// data->mlx->img = mlx_new_image(data->mlx->ptr, WIN_W, WIN_H);
	// data->mlx->buf1 = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
	// 	&data->mlx->length, &data->mlx->endian);

	// t_plane	w[4] =
	// {
	// 	{1, 0, 0, 3},
	// 	{0, 1, 0, 3},
	// 	{0, 1, 0, -3},
	// 	{1, 0, 0, -3}
	// };

	// t_point cam = {0, 0, 0.5};
	// t_point line = {0, 0, 0};
	// t_point inter = {0, 0, 0};

	// i = -1;
	// while (++i <= WIN_W)
	// {
	// 	j = -1;
	// 	while (++j <= WIN_H)
	// 	{
	// 		int k = -1;
	// 		while (++k < 4)
	// 		{
	// 			vect.x = ((i - WIN_W * 0.5) * rh);
	// 			vect.z = ((WIN_H * 0.5 - j) * rv);

	// 			double t = - ((w[k].a * cam.x) + (w[k].b * cam.y) + (w[k].c * cam.z) + w[k].d)
	// 					/ ((w[k].a * vect.x) + (w[k].b * vect.y) + (w[k].c * vect.z));

	// 			line.x = cam.x + vect.x * t;
	// 			line.y = cam.y + vect.y * t;
	// 			line.z = cam.z + vect.z * t;

	// 			if (t > 0 && line.z >= 0 && line.z <= 1)
	// 				put_pixel(i, j, WHITE, data->mlx);
	// 		}
	// 	}
	// }
// }

double	degree_to_radians(double degree)
{
	return (degree * PI / 180);
}

int		precalculate_rays(t_data *data)
{
	double	ray_angle = PLAYER_ANGLE - HALF_FOV;
	int		ray_count;
	t_point ray;

	if (data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	data->mlx->img = mlx_new_image(data->mlx->ptr, WIN_W, WIN_H);
	data->mlx->buf1 = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
		&data->mlx->length, &data->mlx->endian);
	ray_count = -1;
	while (++ray_count < WIN_W)
	{
		ray.x = data->player_x;
		ray.y = data->player_y;

		double raycos = cos(degree_to_radians(ray_angle)) / PRECISION;
		double raysin = sin(degree_to_radians(ray_angle)) / PRECISION;

		char	wall = '0';
		while (wall == '0')
		{
			ray.x += raycos;
			ray.y += raysin;
			wall = data->map->tab[(int)ray.y][(int)ray.x];
		}
		double	distance = sqrt(pow(data->player_x - ray.x, 2)
						+ (pow(data->player_y - ray.y, 2)));

		double	wallheight = (int)(HALF_WIN_H / distance);

		t_point	o;
		o.x = 0;
		o.y = HALF_WIN_H - wallheight;
		put_vline(ray_count, o, BLUE, data->mlx);
		o.x = HALF_WIN_H - wallheight;
		o.y = HALF_WIN_H + wallheight;
		put_vline(ray_count, o, RED, data->mlx);
		o.x = HALF_WIN_H + wallheight;
		o.y = WIN_H;
		put_vline(ray_count, o, GREEN, data->mlx);

		ray_angle += INCREM_ANGLE;
	}
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	return (0);

}
