#include "cub3d.h"

/*** go the document images/sprites/sprites_col.cub
 *	0 is for R2D2
	4 is for the XWING
***/

void	draw_r2d2_xwing_lightsaber(t_data *data, int stripe, int color, int y, int i)
{
	if (i == 0)
		store_buffer_and_print(data, stripe, color, y);
	if (i == 4)
		store_buffer_and_print(data, stripe, color, y);
	if (i == 9 && data->sprites->weapon.weapon_on == FALSE)
		store_buffer_and_print(data, stripe, color, y);
}

/***go the document images/sprites/sprites_col.cub
 *	2 is for the rolling ball ennemy
***/
void	draw_rolling_ball(t_data *data, int stripe, int color, int y, int i)
{
	if (i == 2 && data->sprite_f[i].sprite_die == FALSE)
	{
		data->sprite_f[i].is_seen = TRUE;
		store_buffer_and_print(data, stripe, color, y);
	}
	if (i == 10 && data->sprite_f[i].sprite_die == FALSE)
	{
		data->sprite_f[i].is_seen = TRUE;
		store_buffer_and_print(data, stripe, color, y);
	}
}

void	draw_darth_vader(t_data *data, int stripe, int color, int y, int i)
{
	if (i == 7 && data->sprite_f[i].sprite_die == FALSE)
	{
		data->sprite_f[i].is_seen = TRUE;
		if (data->sprite_f[i].is_seen == TRUE
			&& i == 7
			&& data->move->attack == FALSE)
		{
			store_buffer_and_print(data, stripe, color, y);
		}
	}
}

void	draw_stormtrooper(t_data *data, int stripe, int color, int y, int i)
{
	if (i == 8 && data->sprite_f[i].sprite_die == FALSE)
	{
		data->sprite_f[i].is_seen = TRUE;
		store_buffer_and_print(data, stripe, color, y);
	}
	if (i == 12 && data->sprite_f[i].sprite_die == FALSE)
	{
		data->sprite_f[i].is_seen = TRUE;
		store_buffer_and_print(data, stripe, color, y);
	}
}
