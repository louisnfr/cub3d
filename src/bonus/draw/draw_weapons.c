#include "cub3d.h"

void	draw_weapons(t_data *data)
{
	int	k;
	int	i;
	u_int32_t color;
	//double step;
	//double tex_pos;
	int h;
	int l;
	// int		tex_y;
	// int		tex_x;

	//step = 1.0 * SPRITE_H / 1;
	//tex_pos = (0 - WIN_H * 0.3 + 0.5 * 0.5) * step;
	//data->sprite_f->texx = SPRITE_W - data->sprite_f->texx - 1;
	h = WIN_H * 0.40;
	k = WIN_H * 0.05;
	while (k < WIN_H * 0.70)
	{
		//data->sprite_f->texx = SPRITE_W - data->sprite_f->texx - 1;
		i = (WIN_W * 0.45);
		l = 0;
		while (i < WIN_W * 0.6)
		{
			//data->sprite_f->texy = i * 256 - WIN_H * 128 + (int)tex_pos & (SPRITE_H - 1);
			color = data->sprite_f[1].tex[(int)(512 * l + k)];
			if ((color & 0x00FFFFFF) != 0)
			{
				//printf("data->sprite_f->texy %u\n", l);
				put_pixel(i, h, color, data->mlx);
			}
			l++;
			i++;
		}
		h++;
		k++;
	}
}

// void	draw_weapons(t_data *data)
// {
// 	unsigned int	i;
// 	unsigned int	j;
// 	u_int32_t		color;
// 	unsigned int	index;

// 	i = 0;
// 	// data->sprite_f->frame++;
// 	// if (data->sprite_f->frame == 18)
// 	while (i < 96 * 4)
// 	{
// 		j = 0;
// 		while (j < 96 * 4)
// 		{
// 			color = data->sprite_f[1].tex[(i / 4 + 0 * 96) * 96 + j / 4];

// 			// data->sprite_f->texy = i * 256 - WIN_H * 128 + (int)tex_pos & (SPRITE_H - 1);
// 			// color = data->sprite_f[1].tex[(int)(SPRITE_W * data->sprite_f->texy + k)];
// 			if ((color & 0x00FFFFFF) != 0)
// 			{
// 				put_pixel(i, j, color, data->mlx);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }