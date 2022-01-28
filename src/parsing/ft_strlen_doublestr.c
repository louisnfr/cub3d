#include "cub3d.h"

int	check_number_of_array(char **ceiling_floor_data)
{
	int	i;

	i = 0;
	while (ceiling_floor_data[i])
		i++;
	return (i);
}
