/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:32:47 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/24 14:31:33 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_point a, t_point b, t_data *data)
{
	int dx =  abs (b.x - a.x), sx = a.x < b.x ? 1 : -1;
	int dy = -abs (b.y - a.y), sy = a.y < b.y ? 1 : -1;
 	int err = dx + dy, e2; /* error value e_xy */

  for (;;){  /* loop */
    mlx_pixel_put(data->mlx->ptr, data->mlx->win_ptr, a.x, a.y, GREEN);
    if (a.x == b.x && a.y == b.y) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; a.x += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; a.y += sy; } /* e_xy+e_y < 0 */
  }
	// int	x_step;
	// int	y_step;
	// int		max;

	// x_step = b.x - a.x;
	// y_step = b.y - a.y;
	// printf("%d, %d\n", x_step, y_step);
	// max = ft_max(ft_abs(x_step), ft_abs(y_step));
	// x_step /= max;
	// y_step /= max;
	// while ((int)(a.x - b.x) || (int)(a.y - b.y))
	// {
	// 	if ((a.x > 0 && a.y > 0) && (a.x < HEIGHT && a.y < WIDTH))
	// 	{
	// 		printf("check\n");
	// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, GREEN);
	// 	}
	// 	a.x += x_step;
	// 	a.y += y_step;
	// 	// printf("%d || %d\n", (a.x - b.x), (a.y - b.y));
	// }
}

// void plot_line (int x0, int y0, int x1, int y1)
// {
//   int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
//   int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1;
//   int err = dx + dy, e2; /* error value e_xy */

//   for (;;){  /* loop */
//     setPixel (x0,y0);
//     if (x0 == x1 && y0 == y1) break;
//     e2 = 2 * err;
//     if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
//     if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
//   }
// }
