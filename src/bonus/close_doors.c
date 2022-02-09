#include "cub3d.h"

int	close_doors(t_map *map, t_vector *v, t_doors *doors)
{
	int len_x;
	int len_y;

	len_x = doors->x - v->x;
	len_y = doors->y - v->y;
	if (doors->door_open == TRUE
		&& (len_x > 2 || len_x < -2 || len_y > 2 || len_y < -2))
	{
		map->map[doors->y][doors->x] = '2';
		doors->door_open = FALSE;
	}
	return (SUCCESS);
}