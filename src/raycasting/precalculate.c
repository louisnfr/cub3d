/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:26:00 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/27 23:08:01 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		precalculate_rays(t_data *data)
{
	int	ray_count;

	t_point	vect;

	int	i;
	int	j;

	double	fov;
	double	rh;
	double	rv;

	fov = HALF_FOV ;
	rh = 2 * tan(fov) / WIN_W;
	rv = 2 * tan(fov * WIN_H / (WIN_W * 2)) / WIN_H;

	vect.x = 0;
	vect.y = -1;
	vect.z = 0;

	if (data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	data->mlx->img = mlx_new_image(data->mlx->ptr, WIN_W, WIN_H);
	data->mlx->buf1 = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
		&data->mlx->length, &data->mlx->endian);

	t_plane	w[4] =
	{
		{1, 0, 0, 3},
		{0, 1, 0, 3},
		{0, 1, 0, -3},
		{1, 0, 0, -3}
	};

	t_point cam = {data->player_x, data->player_y, 0.5};
	t_point line = {0, 0, 0};
	t_point inter = {0, 0, 0};

	(void)inter;
	(void)ray_count;

	i = -1;
	while (++i <= WIN_W)
	{
		j = -1;
		while (++j <= WIN_H)
		{
			int k = -1;
			while (++k < 4)
			{
				vect.x = ((i - WIN_W * 0.5) * rh);
				vect.z = ((WIN_H * 0.5 - j) * rv);

				double t = - ((w[k].a * cam.x) + (w[k].b * cam.y) + (w[k].c * cam.z) + w[k].d)
						/ ((w[k].a * vect.x) + (w[k].b * vect.y) + (w[k].c * vect.z));

				line.x = cam.x + vect.x * t;
				line.y = cam.y + vect.y * t;
				line.z = cam.z + vect.z * t;

				if (t > 0 && line.z >= 0 && line.z <= 1)
					put_pixel(i, j, WHITE, data->mlx);
			}
		}
	}
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	return (SUCCESS);
}
