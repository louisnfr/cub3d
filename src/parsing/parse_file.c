#include "cub3d.h"

// static int parsing_map(t_data *data)
// {

// 	return (EXIT_SUCCESS);
// }

// static int parsing_floor(t_data *data)
// {
// 	return (EXIT_SUCCESS);
// }

// static int parsing_ceiling(t_data *data)
// {
// 	return (EXIT_SUCCESS);
// }


int	parse_file(t_data *data)
{
	if (parsing_walls(data))
		return (EXIT_FAILURE);
	// if (parsing_floor(data))
	// 	return (EXIT_FAILURE);
	// if (parsing_ceiling(data))
	// 	return (EXIT_FAILURE);
	// if (parsing_map(data))
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}