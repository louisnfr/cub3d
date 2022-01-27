#include "cub3d.h"

// check de tous les murs

int	parsing_walls(t_data *data)
{
	if (check_all_directions(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
