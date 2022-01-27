#include "cub3d.h"

static int	error_number_ceiling_floor(t_map *map_info)
{
	if (map_info->ceiling_floor[0] != 1 || map_info->ceiling_floor[1] != 1)
	{
		error_message_walls();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int check_if_ceiling_floor_if_good(t_data *data, int i, char *ceiling_or_floor)
{
	if (ft_strncmp(data->map_info->file_cub[i], ceiling_or_floor, 2))
		return(EXIT_FAILURE);
	if (check_and_add_color_ceiling_floor(data, i))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// Je check ici si on rencontre la lettre C ou F

int	check_if_floor_ceiling_exist(t_data *data)
{
	int	i;

	i = -1;

	while (++i < data->map_info->cubfile_number_lines)
	{
		if (!check_if_ceiling_floor_if_good(data, i, "C "))
			data->map_info->ceiling_floor[0]++;
		else if	(!check_if_ceiling_floor_if_good(data, i, "F "))
			data->map_info->ceiling_floor[1]++;
	}
	if (error_number_ceiling_floor(data->map_info))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}