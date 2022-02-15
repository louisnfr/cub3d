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

int	draw_sprites_bonus(t_sprites *spr, t_data *data)
{
	int	stripe;
	int	y;

	stripe = spr->drawstartx;
	y = 0;
	while (stripe < spr->drawendx)
	{
		if (spr->transformy > 0 && stripe > 0 && stripe < WIN_W
			&& spr->transformy < spr->zbuffer[stripe])
		{
			y = spr->drawstarty;
			while (y < spr->drawendy)
			{
				if ((spr->buffer[y][stripe] & 0x00FFFFFF) != 0)
					put_pixel(stripe, y, spr->buffer[y][stripe], data->mlx);
				y++;
			}
		}
		stripe++;
	}
	return (SUCCESS);
}
