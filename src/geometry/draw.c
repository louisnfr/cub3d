/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:32:47 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/24 21:33:04 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(int x, int y, int color, t_mlx *mlx)
{
	char	*dst;

	if (x > 0 && y > 0 && (x < WIN_W && y < WIN_H))
	{
		dst = mlx->buf1 + (y * mlx->length + x * (mlx->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	put_line(t_point a, t_point b, int color, t_mlx *mlx)
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
		if ((a.x > 0 && a.y > 0) && (a.x < WIN_H && a.y < WIN_W))
			put_pixel(a.x, a.y, color, mlx);
		a.x += x_step;
		a.y += y_step;
	}
}
