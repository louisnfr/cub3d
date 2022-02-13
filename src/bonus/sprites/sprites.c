#include "cub3d.h"

/* store the color of the sprite in the buffer
*/

static void	store_color_in_buffer(t_sprites *spr, t_data *data)
{
	int stripe;
	int	texx;
	int	texy;
	int y;
	int d;
	u_int32_t color;

	stripe = spr->drawstartx;

	while (stripe < spr->drawendx)
	{
		texx =
		(int)((256 * (stripe - (-spr->spritewidth * 0.5 + spr->spritescreenx))
		* TEX_W / spr->spritewidth) / 256);
		if (spr->transformy > 0 && stripe > 0 && stripe < WIN_W
			&& spr->transformy < spr->zbuffer[stripe])
		{
			y = spr->drawstarty;

			while (y < spr->drawendy)
			{
				d = (y) * 256 - WIN_H * 128 + spr->spriteheight * 128;
				texy = ((d * TEX_H) / spr->spriteheight) / 256;
				color = spr->barrel.tex[TEX_W * texy + texx];
				if((color & 0x00FFFFFF) != 0)
				{
					spr->buffer[y][stripe] = color;
					put_pixel(stripe, y, color, data->mlx);
				}
				y++;
			}
		}
		stripe++;
	}
}

/*
Find the lowest and the highest pixel of he sprite
*/

static void	lowest_highest_width_pixel(t_sprites *spr)
{
	spr->spritewidth = abs((int)(WIN_H / spr->transformy));
	spr->drawstartx =
		-spr->spritewidth * 0.5 + spr->spritescreenx;
	if (spr->drawstartx < 0)
		spr->drawstartx = 0;
	spr->drawendx = spr->spritewidth / 2 + spr->spritescreenx;
	if (spr->drawendx >= WIN_W)
		spr->drawendx = WIN_W - 1;
}

/*
Find the lowest and the highest pixel of he sprite
*/

static void	lowest_highest_height_pixel(t_sprites *spr)
{
	spr->spriteheight = abs((int)(WIN_H / spr->transformy));
	spr->drawstarty =
		-spr->spriteheight * 0.5 + WIN_H * 0.5;
	if (spr->drawstarty < 0)
		spr->drawstarty = 0;
	spr->drawendy = spr->spriteheight * 0.5 + WIN_H * 0.5;
	if (spr->drawendy >= WIN_H)
		spr->drawendy = WIN_H - 1;
}

static void	sprite_projection(t_data *data, t_sprites *spr, t_vector *player,
						t_ray *ray, t_player *play)
{
	int	i;

	i = 0;
	while(i < NUM_SPRITE)
	{
		spr->spritex = 10.5 - player->x;
		spr->spritey = 3.5 - player->y;
		spr->invdet =
			1.0 / (play->camera.px * player->dy - player->dx * play->camera.py);
		spr->transformx =
			spr->invdet * (player->dy * spr->spritex - player->dx * spr->spritey);
		spr->transformy = spr->invdet *
			(-play->camera.py * spr->spritex + play->camera.px * spr->spritey);
		spr->spritescreenx =
			(int)((WIN_W / 2) * (1 + spr->transformx / spr->transformy));
		lowest_highest_height_pixel(spr);
		lowest_highest_width_pixel(spr);
		store_color_in_buffer(spr, data);
		i++;
	}
}

/* Sort sprite from far to close
*/
static void	sort_sprite_far_to_close(t_sprites *spr, t_data *data,
								t_vector *player)
{
	int i;

	i = 0;
	while (i < NUM_SPRITE)
	{
		spr->sprite_order[i] = i;
    	spr->sprite_distance[i] = ((player->x - 10.5) * (player->x - 10.5) + (player->y - 3.5) * (player->y - 3.5));

		i++;
	}
}

int	sprite_casting(t_data *data, t_sprites *spr, t_vector *player,
				t_ray *ray, t_player *play)
{
	sort_sprite_far_to_close(spr, data, player);
	sprite_projection(data, spr, player, ray, play);
	return (SUCCESS);
}


/*
Set the buffer after raycasting the wall, it contains the distance to the wall
for every vertical stripe.
*/

int	draw_animated_sprites(t_data *data, int x, t_ray *ray)
{
	t_sprites *spr;

	spr = data->sprites;
	spr->zbuffer[x] = ray->pw;
	return (SUCCESS);
}