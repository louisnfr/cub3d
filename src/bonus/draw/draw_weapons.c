#include "cub3d.h"

void	draw_weapons(t_data *data)
{
	int	k;
	int	i;
	u_int32_t color;
	double step;
	double tex_pos;
	int		tex_y;
	int		tex_x;

	step = 1.0 * TEX_H / 0.5;
	tex_pos = (0 - WIN_H * 0.5 + 0.5 * 0.5) * step;
	tex_x = TEX_W - tex_x - 1;
	while (0 < (WIN_W / 0.33))
	{
		tex_y = (int)tex_pos & (TEX_H - 1);
		while (i < (WIN_W * 0.33))
		{
			color = data->sprite_f[1].tex[SPRITE_W * tex_y + k];
			if ((color & 0x00FFFFFF) != 0)
			{
				//put_pixel(i, k, color, data->mlx);
			}
			i++;
		}
		k++;
	}
}