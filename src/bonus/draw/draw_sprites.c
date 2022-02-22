#include "cub3d.h"

/*** Store the color in the buffer
***/

static u_int32_t	store_color(t_sprites *spr,
							int i, t_data *data, u_int32_t color)
{
	if (i != 1)
		color = data->sprite_f[i].tex[SPRITE_W * spr->texy + spr->texx];
	return (color);
}

/* define the texy
*/

void	define_texy(t_sprites *spr, int y)
{
	int	d;

	d = (y) * 256 - WIN_H * 128 + spr->spriteheight * 128;
	spr->texy = ((d * SPRITE_H) / spr->spriteheight) / 256;
}

/* define the texx
*/

void	define_texx(t_sprites *spr, int stripe)
{
	spr->texx = (int)
		((256 * (stripe - (-spr->spritewidth * 0.5 + spr->spritescreenx))
				* SPRITE_W / spr->spritewidth) / 256);
}

void	store_buffer_and_print(t_data *data, int stripe,
										u_int32_t color, int y)
{
	if ((color & 0x00FFFFFF) != 0)
	{
		put_pixel(stripe, y, color, data->mlx);
	}
}

/* define the x && y coordinate to draw the sprite + define which sprite to
	draw
*/

void	store_color_in_buffer(t_sprites *spr, t_data *data, int i)
{
	int			stripe;
	u_int32_t	color;
	int			y;

	stripe = spr->drawstartx;
	while (stripe < spr->drawendx)
	{
		define_texx(spr, stripe);
		if (spr->transformy > 0 && stripe > 0 && stripe < WIN_W
			&& spr->transformy < spr->zbuffer[stripe])
		{
			y = spr->drawstarty;
			while (y < spr->drawendy)
			{
				define_texy(spr, y);
				color = store_color(spr, i, data, color);
				draw_r2d2_xwing(data, stripe, color, y, i);
				draw_stormtrooper(data, stripe, color, y, i);
				draw_darth_vader(data, stripe, color, y, i);
				draw_rolling_ball(data, stripe, color, y, i);
				ennemy_is_hit(spr, data, i);
				y++;
			}
		}
		stripe++;
	}
}
