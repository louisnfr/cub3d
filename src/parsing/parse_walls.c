#include "cub3d.h"

// Check the path for the 4 walls and put the wall into mlx_img
static	void	check_struct_walls(t_data *data, char *face_wall, char *path)
{
	
	if (!ft_strcmp("NO", face_wall))
	{
		// data->sprites->wall_no.path_face = malloc(sizeof (char *) * (ft_strlen(face_wall) + 1));
		data->sprites->wall_no.path_face = ft_ace_wall;
		printf("PROUT_debug %s\n", data->sprites->wall_no.path_face);
		data->sprites->wall_no.path_img = path;
	}
	else if (!ft_strcmp("SO", face_wall))
	{
		data->sprites->wall_so.path_face = face_wall;
		data->sprites->wall_so.path_img = path;
	}
	else if (!ft_strcmp("EA", face_wall))
	{
		data->sprites->wall_ea.path_face = face_wall;
		data->sprites->wall_ea.path_img = path;
	}
	else if (!ft_strcmp("WE", face_wall))
	{
		data->sprites->wall_ea.path_face = face_wall;
		data->sprites->wall_ea.path_img = path;
	}
}

static int	check_and_add_path_walls(t_data *data, int i,
							char *face_wall, int *error)
{
	char	**img;

	// img = NULL;
	img = ft_split_charset(data->map_info->file_cub[i], " \t");
	if (img[2] || ft_strlen(img[0]) != 2)
	{
		free_double_str(img);
		return (EXIT_FAILURE);
	}
	(*error)++;
	check_struct_walls(data, face_wall, img[1]);
	free_double_str(img);
	return (EXIT_SUCCESS);
}

// Check the path for the 4 walls and put the wall into mlx_img
static int	check_if_direction_if_good(t_data *data, int i,
								char *face_wall, int *error)
{
	if (ft_strncmp(data->map_info->file_cub[i], face_wall, 2))
		return (EXIT_FAILURE);
	if (check_and_add_path_walls(data, i, face_wall, error))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// Check each face of the wall

static int	check_all_directions(t_data *data)
{
	int	i;
	int	error;

	i = -1;
	error = 0;
	while (++i < data->map_info->cubfile_number_lines)
	{
		if (!check_if_direction_if_good(data, i, "NO", &error))
		{
			printf("NO\n");
		}
		else if (!check_if_direction_if_good(data, i, "SO", &error))
		{
			printf("SO\n");
		}
		else if (!check_if_direction_if_good(data, i, "WE", &error))
		{
			printf("WE\n");
		}
		else if (!check_if_direction_if_good(data, i, "EA", &error))
		{
			printf("EA\n");
		}
	}
	if (error != 4)
	{
		error_message_walls();
		return (EXIT_FAILURE);
	}
	data->map_info->walls_valid = 1;
	return (EXIT_SUCCESS);
}
// check de tous les murs

int	parsing_walls(t_data *data)
{
	if (check_all_directions(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
