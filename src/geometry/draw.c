/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:32:47 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/25 15:49:26 by lraffin          ###   ########.fr       */
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

void	put_vline(int x, t_point b, int color, t_mlx *mlx)
{
	int	i;

	if (b.y <= b.x)
		return ;
	i = b.x;
	while (i < b.y)
	{
		if ((x >= 0 && x <= WIN_W) && (i >= 0 && i <= WIN_H))
			put_pixel(x, i, color, mlx);
		i++;
		// 	put_pixel(a.x, a.y, color, mlx);
		// a.x += x_step;
		// a.y += y_step;
	}
}
