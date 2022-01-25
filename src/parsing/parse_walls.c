#include "cub3d.h"

static void error_message_walls(void)
{
		ft_putstr_fd("Error\nProblem with your walls in your file cub\n", 2);
}

// Check the path for the 4 walls and put the wall into mlx_img

static int check_and_add_path_walls(t_data *data, int i, char *face_wall)
{
	char **img;

	img = ft_split(data->map_info->file_cub[i], ' ');
	if (img[2])
		return (EXIT_FAILURE);
	if (add_img_wall_to_mlx(data, face_wall, img[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// Check the path for the 4 walls and put the wall into mlx_img
static int check_if_direction_if_good(t_data *data, int i, char *face_wall)
{
	if (ft_strncmp(data->map_info->file_cub[i], face_wall, 2))
		return(EXIT_FAILURE);
	if (check_and_add_path_walls(data, i, face_wall))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


// Check each face of the wall

static int check_all_directions(t_data *data)
{
	int	i;
	int error;

	i = -1;
	error = 0;
	while (++i < data->map_info->cubfile_number_lines)
	{
		if (!check_if_direction_if_good(data, i, "NO"))
			error++;
		else if	(!check_if_direction_if_good(data, i, "SO"))
			error++;
		else if	(!check_if_direction_if_good(data, i, "WE"))
			error++;
		else if	(!check_if_direction_if_good(data, i, "EA"))
			error++;
	}
	if (error != 4)
	{
		error_message_walls();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// check de tous les murs
int parsing_walls(t_data *data)
{
	if (check_all_directions(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}