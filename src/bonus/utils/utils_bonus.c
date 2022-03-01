#include "cub3d.h"

// check the number of times we see the element c

int	ft_strlen_double_str_find_element(char **double_str, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (double_str[i])
	{
		j = 0;
		while (double_str[i][j])
		{
			if (double_str[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	init_bonus_struct(t_data *data)
{
	ft_memset(&data->ray_b, 0, sizeof(t_ray_b));
	ft_memset(data->sprite_f, 0, sizeof(t_sprite_f));
	ft_memset(&data->sprites->ennemy, 0, sizeof(t_ennemy));
	ft_memset(&data->sprites->weapon, 0, sizeof(t_weapon));
	data->sprites->ennemy.rolling_b_dead_1 = FALSE;
	data->sprites->ennemy.rolling_b_dead_2 = FALSE;
	data->sprites->ennemy.rolling_b_dead_3 = FALSE;
	data->sprites->ennemy.rolling_b_dead_4 = FALSE;
	data->sprite_f[12].sprite_die = FALSE;
	data->sprite_f[8].sprite_die = FALSE;
	data->sprites->ennemy.darth_vader = FALSE;
	data->sprites->ennemy.stormtrooper = FALSE;
	data->sprites->weapon.weapon_on = FALSE;
}

//init and store the data for the doors

int	store_data_bonus(t_map *map, t_data *data)
{
	(void) map;
	ft_memset(&data->doors, 0, sizeof(t_doors));
	data->doors.door_open = FALSE;
	return (SUCCESS);
}

int	play_sound(char *path)
{
	char	command[500];

	ft_bzero(command);
	ft_strlcat(command, "(" PLAYER " ", 500);
	ft_strlcat(command, path, 500);
	ft_strlcat(command, BACKGROUND ") " OPTIONS, 500);
	return (system(command));
}
