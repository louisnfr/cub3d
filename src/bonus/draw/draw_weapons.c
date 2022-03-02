#include "cub3d.h"

/*** here we draw the weapon sprite_f[1] is the sprite for the lightsaber
***/

void	draw_attack_lightsaber(t_data *data)
{
	int	k;
	int	i;
	u_int32_t color;
	double	count;
	int h;
	int l;

	count = 0;
	h = WIN_H * 0.40; // useful for the position of the light saber
	k = WIN_H * 0.05;
	while (k < WIN_H * 0.70)
	{
		i = (WIN_W * 0.65);
		l = 0;
		while (i < WIN_W * 0.8)
		{
			color = data->sprite_f[1].tex[(int)(512 * l + k)];
			if ((color & 0x00FFFFFF) != 0)
				put_pixel((int)(l + count + 400), h, color, data->mlx);
			l++;
			i++;
		}
		count += 0.7;
		h++;
		k++;
	}
}

static void	draw_lightsaber(t_data *data)
{
	int	k;
	int	i;
	u_int32_t color;
	int h;
	int l;

	h = WIN_H * 0.40;
	k = WIN_H * 0.05;
	while (k < WIN_H * 0.70)
	{
		i = (WIN_W * 0.65);
		l = 0;
		while (i < WIN_W * 0.8)
		{
			color = data->sprite_f[1].tex[(int)(512 * l + k)];
			if ((color & 0x00FFFFFF) != 0)
				put_pixel(i, h, color, data->mlx);
			l++;
			i++;
		}
		h++;
		k++;
	}
}

void light_saber_is_taken(t_data *data, int stripe, int y, int i)
{
	if (data->sprites->weapon.weapon_on == FALSE)
	{
		if ((int)data->sprite_f[i].spritex == 0
			&& (int)data->sprite_f[i].spritey == 0
			&& !ft_strcmp(data->sprite_f[i].name, "LSG"))
		{
			play_sound(ignition, 50);
			data->sprites->weapon.weapon_on = TRUE;
		}
	}
}

void draw_weapons(t_data *data)
{
	if (data->move->attack == FALSE)
		draw_lightsaber(data);
	else if(data->move->attack == TRUE)
		draw_attack_lightsaber(data);
}
