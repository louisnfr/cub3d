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
	data->sprites->ennemy.rolling_b_dead = FALSE;
	data->sprites->ennemy.darth_vader = FALSE;
	data->sprites->ennemy.stormtrooper = FALSE;
}

//init and store the data for the doors

int	store_data_bonus(t_map *map, t_data *data)
{
	(void) map;
	ft_memset(&data->doors, 0, sizeof(t_doors));
	data->doors.door_open = FALSE;
	return (SUCCESS);
}
