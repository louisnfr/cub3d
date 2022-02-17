#include "cub3d.h"

// void	ennemy_is_darth_vador(t_sprites *spr, t_data *data, int i)
// {
// 	int			stripe;
// 	u_int32_t	color;
// 	int			y;

// 	if (spr->transformy > 0 && (int)data->sprite_f[i].spritex == 0
// 		&& (int)data->sprite_f[i].spritey == 0
// 		&& !ft_strcmp(data->sprite_f[i].name, "DVO"))
// 	{
// 		stripe = spr->drawstartx;
// 		while (stripe < spr->drawendx)
// 		{
// 			define_texx(spr, stripe);
// 			if (spr->transformy > 0 && stripe > 0 && stripe < WIN_W
// 				&& spr->transformy < spr->zbuffer[stripe])
// 			{
// 				y = spr->drawstarty;
// 				while (y < spr->drawendy)
// 				{
// 					define_texy(spr, y);
// 					color =
// 						data->sprite_f[2].tex[SPRITE_W * spr->texy + spr->texx];
// 					store_buffer_and_print(data, stripe, color, y);
// 					y++;
// 				}
// 			}
// 			stripe++;
// 		}
// 	}
// }

void	ennemy_is_rolling_ball(t_sprites *spr, t_data *data, int i)
{
	int			stripe;
	u_int32_t	color;
	int			y;

	if ((int)data->sprite_f[i].spritex == 0
		&& (int)data->sprite_f[i].spritey == 0
		&& !ft_strcmp(data->sprite_f[i].name, "RB"))
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
						data->sprite_f[2].tex[SPRITE_W * spr->texy + spr->texx];
					store_buffer_and_print(data, stripe, color, y);
					y++;
				}
			}
			stripe++;
		}
	}
}