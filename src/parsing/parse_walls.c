#include "cub3d.h"

// je check si les 3 premieres lettres sont bonnes

static void error_message_walls(char *str)
{
	ft_putstr_fd("Error\nProblem with your walls :", 2);
	ft_putstr_fd(str, 2);
}

// Check if all wall have the right wording

static int check_if_direction_if_good(t_data *data, int i, char *str)
{
	if (ft_strncmp(data->map_info->file_cub[i], str, 3))
	{
		printf("prout.debug_WALL\n");
		error_message_walls(str);
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// Check the path for the 4 walls and put the wall into mlx_img

static int check_path_walls(t_data *data)
{
	(void) data;
	return (EXIT_SUCCESS);
}

// Check the letters of the 4 walls
static int check_all_directions(t_data *data)
{
	if (check_if_direction_if_good(data, 0, "NO "))
		return (EXIT_FAILURE);
	if	(check_if_direction_if_good(data, 1, "SO "))
		return (EXIT_FAILURE);
	if (check_if_direction_if_good(data, 2, "WE "))
		return (EXIT_FAILURE);
	if (check_if_direction_if_good(data, 3, "EA "))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// check de tous les murs
int parsing_walls(t_data *data)
{
	if (check_all_directions(data))
		return (EXIT_FAILURE);
	if (check_path_walls(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}