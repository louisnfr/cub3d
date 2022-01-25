#include "cub3d.h"

static	int	check_and_add_color_ceiling_floor(t_data *data, int i, char *ceiling_or_floor)
{
	char **img;

	img = ft_split(data->map_info->file_cub[i], ' ');
	if (img[2])
		return (EXIT_FAILURE);
	if (add_img_floor_ceiling_to_mlx(data, ceiling_or_floor, img[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
static int check_if_direction_if_good(t_data *data, int i, char *ceiling_or_floor)
{
	if (ft_strncmp(data->map_info->file_cub[i], ceiling_or_floor, 2))
		return(EXIT_FAILURE);
	if (check_and_add_color_ceiling_floor(data, i, ceiling_or_floor))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int	check_if_floor_ceiling_exist(t_data *data)
{
	int	i;
	int error_ceiling;
	int	error_floor;

	i = -1;
	error_ceiling = 0;
	error_floor = 0;

	while (++i < data->map_info->cubfile_number_lines)
	{
		if (!check_if_ceiling_if_good(data, i, "C "))
			error_ceiling++;
		else if	(!check_if_floor_if_good(data, i, "F "))
			error_floor++;
	}
	if (error_ceiling != 1 || error_floor != 1)
	{
		error_message_walls();
		return (EXIT_FAILURE);
	}
}

int parsing_floor_ceiling(t_data *data)
{
	if (check_if_floor_ceiling_exist(data))
		return (EXIT_FAILURE);
}