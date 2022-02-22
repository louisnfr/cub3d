#include "cub3d.h"

void	ennemy_is_stormtrooper(t_sprites *spr, t_data *data, int i)
{
	int			stripe;
	u_int32_t	color;
	int			y;

	if (spr->transformy > 0 && (int)data->sprite_f[i].spritex == 0
		&& (int)data->sprite_f[i].spritey == 0
		&& !ft_strcmp(data->sprite_f[i].name, "ST")
		&& data->move->attack == TRUE
		&& data->sprites->ennemy.stormtrooper == FALSE)
	{
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
					color =
						data->sprite_f[3].tex[SPRITE_W * spr->texy + spr->texx];
					store_buffer_and_print(data, stripe, color, y);
					y++;
				}
			}

			stripe++;
		}
		data->sprites->ennemy.stormtrooper = TRUE;
	}
}

/***
     Function to say if you hit darth_vader we draw kill him
***/

void	ennemy_is_darth_vador(t_sprites *spr, t_data *data, int i)
{
	int			stripe;
	u_int32_t	color;
	int			y;

	if (spr->transformy > 0 && (int)data->sprite_f[i].spritex == 0
		&& (int)data->sprite_f[i].spritey == 0
		&& !ft_strcmp(data->sprite_f[i].name, "DVM")
		&& data->move->attack == TRUE
		&& data->sprites->ennemy.darth_vader == FALSE)
	{
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
					color =
						data->sprite_f[3].tex[SPRITE_W * spr->texy + spr->texx];
					store_buffer_and_print(data, stripe, color, y);
					y++;
				}
			}
			stripe++;
		}
		data->sprites->ennemy.darth_vader = TRUE;
	}
}

/***
     Function to say if you hit the rolling ball we draw the explosion
***/

void	ennemy_is_rolling_ball(t_sprites *spr, t_data *data, int i)
{
	int			stripe;
	u_int32_t	color;
	int			y;

	if ((int)data->sprite_f[i].spritex == 0
		&& (int)data->sprite_f[i].spritey == 0
		&& !ft_strcmp(data->sprite_f[i].name, "RB")
		&& data->move->attack == TRUE
		&& data->sprites->ennemy.rolling_b_dead == FALSE)
	{
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
					color =
						data->sprite_f[3].tex[SPRITE_W * spr->texy + spr->texx];
					store_buffer_and_print(data, stripe, color, y);
					y++;
				}
			}
			stripe++;
		}
		data->sprites->ennemy.rolling_b_dead = TRUE;
	}
}

void	ennemy_is_hit(t_sprites *spr, t_data *data, int i)
{
	if (data->sprites->ennemy.rolling_b_dead == FALSE)
		ennemy_is_rolling_ball(spr, data, i);
	if (data->sprites->ennemy.darth_vader == FALSE)
		ennemy_is_darth_vador(spr, data, i);
	if (data->sprites->ennemy.stormtrooper == FALSE)
		ennemy_is_stormtrooper(spr, data, i);
}