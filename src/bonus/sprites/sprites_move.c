#include "cub3d.h"

static int sprites_move_backward(t_data *data, t_vector *vect, int i)
{
	int x;
	int y;

	x = data->map_info->map[(int)data->sprite_f[i].y][(int)data->sprite_f[i].x];
	y = data->map_info->map[(int)data->sprite_f[i].y][(int)data->sprite_f[i].x];
	if (data->sprites->transformy > 0
		&& x != '1' && y != '2' && y != '3')
	{
		data->sprite_f[i].x =
		data->sprite_f[i].x - ((data->sprite_f[i].x - vect->x) * 0.02);
		data->sprite_f[i].y =
		data->sprite_f[i].y - ((data->sprite_f[i].y - vect->y) * 0.02);
		if ((int)data->sprite_f[1].spritex == 0
			&& (int)data->sprite_f[1].spritey == 0)
		{
			sleep(2);
			ft_exit_parsing(data, "YOU LOOSE");
		}
	}
	return (SUCCESS);
}

static int sprites_move_forward(t_data *data, t_vector *vect, int i)
{
	int	x;
	int	y;

	x = data->map_info->map[(int)data->sprite_f[i].y][(int)data->sprite_f[i].x];
	y = data->map_info->map[(int)data->sprite_f[i].y][(int)data->sprite_f[i].x];
	if (data->sprites->transformy > 0
		&& x != '1' && y != '2' && y != '3')
	{
		data->sprite_f[i].x =
		data->sprite_f[i].x - ((data->sprite_f[i].x - vect->x) * 0.01);
		data->sprite_f[i].y =
		data->sprite_f[i].y - ((data->sprite_f[i].y - vect->y) * 0.01);
		if ((int)data->sprite_f[1].spritex == 0
			&& (int)data->sprite_f[1].spritey == 0)
		{
			sleep(2);
			ft_exit_parsing(data, "YOU LOOSE");
		}
	}
	return (SUCCESS);
}

int	sprites_move(t_data *data, int a, t_vector *vect)
{
	int	i;

	i = 0;
	while (i < data->sprites->num_sprites)
	{
		if (a == 1 && data->sprite_f[i].is_ennemy == TRUE)
			sprites_move_forward(data, vect, i);
		if (a == 2 && data->sprite_f[i].is_ennemy == TRUE)
			sprites_move_backward(data, vect, i);
		i++;
	}
	return (SUCCESS);
}