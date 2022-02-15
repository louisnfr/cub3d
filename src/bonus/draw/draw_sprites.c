#include "cub3d.h"

/*** Store the color in the buffer
***/

static u_int32_t	store_color(t_sprites *spr,
							int i, t_data *data, u_int32_t color)
{
	color = data->sprite_f[i].tex[SPRITE_W * spr->texy + spr->texx];
	return (color);
}

/* define the texy
*/

static void	define_texy(t_sprites *spr, int y)
{
	int	d;

	d = (y) * 256 - WIN_H * 128 + spr->spriteheight * 128;
	spr->texy = ((d * SPRITE_H) / spr->spriteheight) / 256;
}

/* define the texx
*/

static void	define_texx(t_sprites *spr, int stripe)
{
	spr->texx = (int)
		((256 * (stripe - (-spr->spritewidth * 0.5 + spr->spritescreenx))
				* SPRITE_W / spr->spritewidth) / 256);
}

static void	store_buffer_and_print(t_data *data, int stripe,
										u_int32_t color, int y)
{
	if ((color & 0x00FFFFFF) != 0)
	{
		// spr->buffer[y][stripe] = color;
		put_pixel(stripe, y, color, data->mlx);
	}
}

/* store the color of the sprite in the buffer
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
				store_buffer_and_print(data, stripe, color, y);
				y++;
			}
		}
		stripe++;
	}
}
