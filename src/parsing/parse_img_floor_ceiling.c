#include "cub3d.h"

int	add_img_floor_ceiling_to_mlx(t_data *data,
			char *ceiling_or_floor, char *path)
{
	if (!ft_strcmp(ceiling_or_floor, "C"))
	{
		data->map_info->color_floor = path;
		return (EXIT_FAILURE);
	}
	else if (!ft_strcmp(ceiling_or_floor, "F"))
	{
		data->map_info->color_floor = path;
		return (EXIT_FAILURE);
	}
}
