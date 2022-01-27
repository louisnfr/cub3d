#include "cub3d.h"

// chaque fonction renvoie vers un fichier associe
static int	check_if_all_file_is_good(t_data *data)
{

	if (data->map_info->floor_ceiling_valid != 1
		&& data->map_info->walls_valid != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


int	parse_file(t_data *data)
{
	if (parsing_walls(data))
		return (EXIT_FAILURE);
	if (parsing_floor_ceiling(data))
		return (EXIT_FAILURE);
	// if (parsing_map(data))
	// 	return (EXIT_FAILURE);
	if (check_if_all_file_is_good(data))
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
