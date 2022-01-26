#include "cub3d.h"

// chaque fonction renvoie vers un fichier associe

int	parse_file(t_data *data)
{
	if (parsing_walls(data))
		return (EXIT_FAILURE);
	// if (parsing_floor_ceiling(data))
	// 	return (EXIT_FAILURE);
	// if (parsing_map(data))
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
