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

static void	draw_sprite(t_data *data, int stripe, int color, int y,
						int i, t_sprites *spr)
{
	draw_r2d2_xwing_lightsaber(data, stripe, color, y, i);
	draw_stormtrooper(data, stripe, color, y, i);
	draw_darth_vader(data, stripe, color, y, i);
	draw_rolling_ball(data, stripe, color, y, i);
	ennemy_is_hit(spr, data, i);
	// if ((int)data->sprite_f[0].spritex == 0
	// 	&& (int)data->sprite_f[0].spritey == 0)
	// 	play_sound(R2D2);
	xwing_end(spr, data, i);
}

void	store_color_in_buffer(t_sprites *spr, t_data *data, int i)
{
	u_int32_t	color;
	int			y;

	y = 0;
	data->sprites->stripe = data->sprites->drawstartx;
	light_saber_is_taken(data, data->sprites->stripe, y, i);
	while (data->sprites->stripe < spr->drawendx)
	{
		define_texx(spr, data->sprites->stripe);
		if (data->sprites->transformy > 0 && data->sprites->stripe > 0
			&& data->sprites->stripe < WIN_W
			&& data->sprites->transformy
			< data->sprites->zbuffer[data->sprites->stripe])
		{
			y = data->sprites->drawstarty;
			while (y < data->sprites->drawendy)
			{
				define_texy(spr, y);
				color = store_color(spr, i, data, color);
				draw_sprite(data, data->sprites->stripe, color, y, i, spr);
				y++;
			}
		}
		data->sprites->stripe++;
	}
}
