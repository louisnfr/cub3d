#include "cub3d.h"

static void	open_north_doors(t_map *map, t_vector *v, t_doors *doors)
{
	if (map->map[(int)v->y + 1][(int)v->x] != '1')
	{
		if (map->map[(int)v->y + 1][(int)v->x] == '2'
			&& doors->door_open == FALSE)
		{
			doors->y = (int)v->y + 1;
			doors->x = (int)v->x;
			map->map[(int)v->y + 1][(int)v->x] = '3';
			doors->door_open = TRUE;
		}
	}
}

static void	open_south_doors(t_map *map, t_vector *v, t_doors *doors)
{
	if (map->map[(int)v->y - 1][(int)v->x] != '1')
	{
		if (map->map[(int)v->y - 1][(int)v->x] == '2'
			&& doors->door_open == FALSE)
		{
			doors->y = (int)v->y - 1;
			doors->x = (int)v->x;
			map->map[(int)v->y - 1][(int)v->x] = '3';
			doors->door_open = TRUE;
		}
	}
}

static void	open_east_doors(t_map *map, t_vector *v, t_doors *doors)
{
	if (map->map[(int)v->y][(int)v->x + 1] != '1')
	{
		if (map->map[(int)v->y][(int)v->x + 1] == '2'
			&& doors->door_open == FALSE)
		{
			doors->y = (int)v->y;
			doors->x = (int)v->x + 1;
			map->map[(int)v->y][(int)v->x + 1] = '3';
			doors->door_open = TRUE;
		}
	}
}

static void	open_west_doors(t_map *map, t_vector *v, t_doors *doors)
{
	if (map->map[(int)v->y][(int)v->x - 1] != '1')
	{
		if (map->map[(int)v->y][(int)v->x - 1] == '2'
			&& doors->door_open == FALSE)
		{
			doors->y = (int)v->y;
			doors->x = (int)v->x - 1;
			map->map[(int)v->y][(int)v->x - 1] = '3';
			doors->door_open = TRUE;
		}
	}
}

int	doors(t_data *data)
{
	t_map		*map;
	t_vector	v;
	int			x_p;
	int			y_p;

	v = data->player->vector;
	map = data->map_info;
	x_p = v.x + v.dx;
	y_p = v.y + v.dx;
	open_west_doors(map, &v, &data->doors);
	open_south_doors(map, &v, &data->doors);
	open_north_doors(map, &v, &data->doors);
	open_east_doors(map, &v, &data->doors);
	close_doors(map, &v, &data->doors);
	return (SUCCESS);
}
