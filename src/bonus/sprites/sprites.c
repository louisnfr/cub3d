#include "cub3d.h"

static void	sprite_projection(t_data *data, t_sprites *spr, t_vector *player,
						t_player *play)
{
	int	i;

	i = 0;
	while (i < data->sprites->num_sprites)
	{
		data->sprite_f[i].spritex = data->sprite_f[i].x - player->x;
		data->sprite_f[i].spritey = data->sprite_f[i].y - player->y;
		spr->invdet
			= 1.0
			/ (play->camera.px * player->dy - player->dx * play->camera.py);
		spr->transformx
			= spr->invdet
			* (player->dy * data->sprite_f[i].spritex - player->dx * data->sprite_f[i].spritey);
		spr->transformy
			= spr->invdet
			* (-play->camera.py * data->sprite_f[i].spritex
				+ play->camera.px * data->sprite_f[i].spritey);
		spr->spritescreenx
			= (int)((WIN_W / 2) * (1 + spr->transformx / spr->transformy));
		lowest_highest_height_pixel(spr);
		lowest_highest_width_pixel(spr);
		store_color_in_buffer(spr, data, i);
		i++;
	}
}

/* Sort sprite from far to close
*/
static void	sort_sprite_far_to_close(t_sprites *spr,
								t_vector *player, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->sprites->num_sprites)
	{
		spr->sprite_order[i] = i;
		spr->sprite_distance[i]
			= ((player->x - data->sprite_f[i].x)
				* (player->x - data->sprite_f[i].x)
				+ (player->y - data->sprite_f[i].y)
				* (player->y - data->sprite_f[i].y));
		i++;
	}
}

int	sprite_casting(t_data *data, t_sprites *spr, t_vector *player,
						t_player *play)
{
	sort_sprite_far_to_close(spr, player, data);
	sprite_projection(data, spr, player, play);
	return (SUCCESS);
}

/*
Set the buffer after raycasting the wall, it contains the distance to the wall
for every vertical stripe.
*/

int	draw_animated_sprites(t_data *data, int x, t_ray *ray)
{
	t_sprites	*spr;

	spr = data->sprites;
	spr->zbuffer[x] = ray->pw;
	return (SUCCESS);
}
