#include "cub3d.h"

int parsing_floor_ceiling(t_data *data)
{
	if (check_if_floor_ceiling_exist(data))
		return (EXIT_FAILURE);
	data->map_info->floor_ceiling_valid = 1;
	return (EXIT_SUCCESS);
}