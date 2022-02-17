#include "cub3d.h"

/* Function to put every pixel in the minimap
*/

static void	cub_map_wall(float size_w, t_minimap pos, t_mlx *mlx, int color)
{
	int		k;
	int		l;
	int		x;
	int		y;

	k = 0;
	while (k < size_w)
	{
		l = 0;
		while (l < size_w)
		{
			x = (pos.x * size_w) + l;
			y = (pos.y * size_w) + k;
			put_pixel(x, y, color, mlx);
			l++;
		}
		k++;
	}
}

/* Loop to display the minimap
*/

static void	loop_display_minimap(t_data *data, t_map *map
								, t_mlx *mlx, float size_w)
{
	while (data->minimap.y < data->minimap.length_y)
	{
		data->minimap.x = 0;
		while (data->minimap.x < data->minimap.length_x)
		{
			if (map->map[data->minimap.y][data->minimap.x] == ' '
				|| map->map[data->minimap.y][data->minimap.x] == '\t')
				cub_map_wall(size_w, data->minimap, mlx, GREY);
			if (map->map[data->minimap.y][data->minimap.x] == '0')
				cub_map_wall(size_w, data->minimap, mlx, BLACK);
			if (map->map[data->minimap.y][data->minimap.x] == '1')
				cub_map_wall(size_w, data->minimap, mlx, WHITE);
			if (map->map[data->minimap.y][data->minimap.x] == '2')
				cub_map_wall(size_w, data->minimap, mlx, GREEN);
			if (map->map[data->minimap.y][data->minimap.x] == 'N'
				||map->map[data->minimap.y][data->minimap.x] == 'S'
				||map->map[data->minimap.y][data->minimap.x] == 'W'
				||map->map[data->minimap.y][data->minimap.x] == 'E')
				cub_map_wall(size_w, data->minimap, mlx, BLACK);
			if (data->minimap.x == (int)data->player->vector.x
				&& data->minimap.y == (int)data->player->vector.y)
				cub_map_wall(size_w, data->minimap, mlx, YELLOW);
			data->minimap.x++;
		}
		data->minimap.y++;
	}
}

static void	init_minimap_struct(t_data *data, t_map *map)
{
	ft_memset(&data->minimap, 0, sizeof(data->minimap));
	data->minimap.length_x = map->map_width_line;
	data->minimap.length_y = ft_strlen_double_str(map->map);
}

/* Define the size of the minimap
	- offset = the length of a square in the map
	- size_w = new size for the square of the mini map
*/

static void	display_map(t_data *data, t_map *map, t_mlx *mlx)
{
	float	size_w;
	float	offset_w;

	init_minimap_struct(data, map);
	offset_w = WIN_W / data->minimap.length_x;
	size_w = offset_w * MAP_SIZE;
	loop_display_minimap(data, map, mlx, size_w);
}

// Function to display the mini-map when pressing M button

int	mini_map(t_data *data)
{
	if (data->move->minimap)
	{
		display_map(data, data->map_info, data->mlx);
		// move_player_minimap(data);
	}
	return (0);
}
