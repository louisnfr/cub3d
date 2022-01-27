#include "cub3d.h"

// check de tous les murs

int	parsing_walls(t_data *data)
{
	if (check_all_directions(data))
		return (EXIT_FAILURE);
	data->map_info->walls_valid = 1;
	return (EXIT_SUCCESS);
}
