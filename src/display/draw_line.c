/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:32:47 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/18 15:55:46 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_point a, t_point b, t_data *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if ((a.x > 0 && a.y > 0) && (a.x < HEIGHT && a.y < WIDTH))
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, GREEN);
		a.x += x_step;
		a.y += y_step;
	}
}
