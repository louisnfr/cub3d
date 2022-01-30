#include "cub3d.h"

static int	check_if_too_much_walls_lines(int *check)
{
	if (check[0] != 1 || check[1] != 1 || check[2] != 1 || check[3] != 1)
	{
		printf("too_much_line\n");
		error_message_walls();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_if_walls_is_invalid(t_map *map_info)
{
	if (map_info->walls_invalid == 1)
	{
		error_message_walls();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_if_direction_if_good(t_data *data, int i,
								char *face_wall)
{
	if (ft_strncmp(data->map_info->file_cub[i], face_wall, 2))
		return (EXIT_FAILURE);
	if (data->map_info->file_cub[0][2] != ' ' && data->map_info->file_cub[0][2] != '\t') // acorriger
		data->map_info->walls_invalid = 1;
	if (check_and_add_path_walls(data, i, face_wall))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	loop_check_face_walls(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map_info->cubfile_number_lines)
	{
		if (!check_if_direction_if_good(data, i, "NO"))
			data->sprites->check[0]++;
		else if (!check_if_direction_if_good(data, i, "SO"))
			data->sprites->check[1]++;
		else if (!check_if_direction_if_good(data, i, "WE"))
			data->sprites->check[2]++;
		else if (!check_if_direction_if_good(data, i, "EA"))
			data->sprites->check[3]++;
	}
	return (EXIT_SUCCESS);
}

int	check_all_directions(t_data *data)
{
	int	i;

	i = -1;
	ft_memset(data->sprites->check, 0, sizeof (int) * 4);
	loop_check_face_walls(data);
	if (check_if_too_much_walls_lines(data->sprites->check)
		|| check_if_walls_is_invalid(data->map_info))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
