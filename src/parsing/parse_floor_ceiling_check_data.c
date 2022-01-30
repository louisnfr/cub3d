#include "cub3d.h"

//check if ceiling_floor_is_invalid

static int	error_number_ceiling_floor(t_map *map_info)
{
	if (map_info->ceiling_floor[0] != 1 || map_info->ceiling_floor[1] != 1
		|| map_info->floor_ceiling_invalid == 1)
	{
		error_message_walls();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// check 1st letter and check if not duplicated C or F + go to the file color

static int	check_if_ceiling_floor_if_good(t_data *data, int i,
	char *ceiling_or_floor, int *check)
{
	if (ft_strncmp(data->map_info->file_cub[i], ceiling_or_floor, 1))
		return (EXIT_FAILURE);
	if (data->map_info->file_cub[i][1] != ' ' && data->map_info->file_cub[i][1] != '\t') // acorriger
	{
		data->map_info->walls_invalid = 1;
		return (EXIT_FAILURE);
	}
	(*check)++;
	if ((*check) == 2)
	{
		data->map_info->floor_ceiling_invalid = 1;
		return (EXIT_FAILURE);
	}
	if (check_and_add_color_ceiling_floor(data, i))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// Je check ici si on rencontre la lettre C ou F + error

int	check_if_floor_ceiling_exist(t_data *data)
{
	int	i;
	int	check_c;
	int	check_f;

	i = 0;
	check_f = 0;
	check_c = 0;
	while (++i < data->map_info->cubfile_number_lines)
	{
		if (!check_if_ceiling_floor_if_good(data, i, "C", &check_c))
			data->map_info->ceiling_floor[0]++;
		else if (!check_if_ceiling_floor_if_good(data, i, "F", &check_f))
			data->map_info->ceiling_floor[1]++;
	}
	// printf("i = %d --- data->map_info->invalid[0] == C == %d\n", i, data->map_info->ceiling_floor[0]);
	if (error_number_ceiling_floor(data->map_info))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
