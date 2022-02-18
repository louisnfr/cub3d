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
}

/*
init and store the data for the doors
*/
int	store_data_bonus(t_map *map, t_data *data)
{
	(void) map;
	ft_memset(&data->doors, 0, sizeof(t_doors));
	data->doors.door_open = FALSE;
	return (SUCCESS);
}

/*
play a .wav sound
*/

int	play_sound(char *path)
{
	char	command[1000];

	ft_bzero(command);
	ft_strlcat(command, "(" PLAYER " ", 1000);
	ft_strlcat(command, path, 1000);
	ft_strlcat(command, BACKGROUND ") " OPTIONS, 1000);
	return (system(command));
}
