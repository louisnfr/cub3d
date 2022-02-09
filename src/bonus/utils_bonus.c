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

//init and store the data for the doors

int	store_data_bonus(t_map *map, t_data *data)
{
	(void) map;
	ft_memset(&data->doors, 0, sizeof(t_doors));
	data->doors.door_open = FALSE;
	return (SUCCESS);
}