#include "cub3d.h"

static int	check_and_store_map(t_data *data)
{
	if (map_if_in_good_place(data->map_info))
		return (EXIT_FAILURE);
	if (store_data_map(data->map_info))
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parsing_map(t_data *data)
{
	if (check_and_store_map(data))
		return (EXIT_FAILURE);
	// if (check_errors_map(data))
	// 	return (EXIT_FAILURE);
	data->map_info->map_valid = 1;
	return (EXIT_SUCCESS);
}