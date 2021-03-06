#include "cub3d.h"

void	ennemy_is_stormtrooper(t_sprites *spr, t_data *data, int i)
{
	int			stripe;
	u_int32_t	color;
	int			y;

	if (spr->transformy > 0 && (int)data->sprite_f[i].spritex == 0
		&& (int)data->sprite_f[i].spritey == 0
		&& data->move->attack == TRUE
		&& ((i == 8 && data->sprite_f[i].sprite_die == FALSE)
		|| (i == 12 && data->sprite_f[i].sprite_die == FALSE)))
	{
		play_sound(WILHELM, 75);
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
						data->sprite_f[11].tex[SPRITE_W * spr->texy + spr->texx];
					store_buffer_and_print(data, stripe, color, y);
					y++;
				}
			}

			stripe++;
		}
		data->sprite_f[i].sprite_die = TRUE;
	}
}

/***
     Function to say if you hit darth_vader we draw kill him
***/
void	ennemy_is_darth_vador_second_attack(t_sprites *spr, t_data *data, int i)
{
	int			stripe;
	u_int32_t	color;
	int			y;

	if (spr->transformy > 0 && (int)data->sprite_f[i].spritex == 0
		&& (int)data->sprite_f[i].spritey == 0
		&& i == 7
		&& data->move->attack == TRUE && data->sprite_f[7].number_attack >= 6)
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
						data->sprite_f[5].tex[SPRITE_W * spr->texy + spr->texx];
					store_buffer_and_print(data, stripe, color, y);
					y++;
				}
			}
			stripe++;
		}
		data->sprite_f[7].number_attack++;
		if (data->sprite_f[7].number_attack == 8)
		{
			play_sound(dv_death, 75);
			data->sprite_f[i].sprite_die = TRUE;
		}
		//printf("PROUT_debug %d\n", data->sprite_f[7].number_attack);
	}
}

void	ennemy_is_darth_vador_first_attack(t_sprites *spr, t_data *data, int i)
{
	int			stripe;
	u_int32_t	color;
	int			y;

	if (spr->transformy > 0 && (int)data->sprite_f[i].spritex == 0
		&& (int)data->sprite_f[i].spritey == 0
		&& i == 7
		&& data->move->attack == TRUE && data->sprite_f[7].number_attack < 6)
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
						data->sprite_f[6].tex[SPRITE_W * spr->texy + spr->texx];
					store_buffer_and_print(data, stripe, color, y);
					y++;
				}
			}
			stripe++;
		}
		play_sound(combat, 60);
		data->sprite_f[7].number_attack++;
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
		&& data->move->attack == TRUE
		&& ((i == 2 && data->sprite_f[i].sprite_die == FALSE)
		|| (i == 10 && data->sprite_f[i].sprite_die == FALSE)
		|| (i == 15 && data->sprite_f[i].sprite_die == FALSE)
		|| (i == 16 && data->sprite_f[i].sprite_die == FALSE)))
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
		data->sprite_f[i].sprite_die = TRUE;
		play_sound(droid_death, 70);
		play_sound(explosion, 50);
	}
}

void	xwing_end(t_sprites *spr, t_data *data, int i)
{
	if (data->sprite_f[7].sprite_die == TRUE
		&& data->sprites->weapon.weapon_on == TRUE)
	{
		if ((int)data->sprite_f[4].spritex == 0
			&& (int)data->sprite_f[4].spritey == 0)
		{

			system("killall paplay");
			play_sound(xwing, 100);
			sleep(10);
			system("killall paplay");
			ft_exit_parsing(data, "You WON\n");
		}
	}
}

void	ennemy_is_hit(t_sprites *spr, t_data *data, int i)
{
	if (data->sprite_f[i].sprite_die == FALSE
		&& data->sprites->weapon.weapon_on == TRUE
		&& data->sprite_f[i].is_seen == TRUE)
		ennemy_is_rolling_ball(spr, data, i);
	if (data->sprite_f[7].sprite_die == FALSE
		&& data->sprites->weapon.weapon_on == TRUE
		&& data->sprite_f[7].is_seen == TRUE
		&& data->sprite_f[7].number_attack < 6)
		ennemy_is_darth_vador_first_attack(spr, data, i);
	else if (data->sprite_f[7].sprite_die == FALSE
		&& data->sprites->weapon.weapon_on == TRUE
		&& data->sprite_f[7].is_seen == TRUE
		&& data->sprite_f[7].number_attack >= 6)

	{
		ennemy_is_darth_vador_second_attack(spr, data, i);
	}
	if (data->sprite_f[i].sprite_die == FALSE
		&& data->sprites->weapon.weapon_on == TRUE
		&& data->sprite_f[i].is_seen == TRUE && (i == 8 || i == 12))
		ennemy_is_stormtrooper(spr, data, i);
}
