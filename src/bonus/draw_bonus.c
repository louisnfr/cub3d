#include "cub3d.h"

int	draw_floor_ceiling_bonus(t_ray_b *ray_b, t_data *data)
{
	int	k;
	int	x;

	k = 0;
	while (k < (WIN_H - k))
	{
		x = 0;
		while (x < WIN_W)
		{
			put_pixel(x, k, ray_b->buffer[k][x], data->mlx);
			x++;
		}
		k++;
	}
	while (k < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			put_pixel(x, k, ray_b->buffer[k][x], data->mlx);
			x++;
		}
		k++;
	}
	return (SUCCESS);
}
