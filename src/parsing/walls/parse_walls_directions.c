/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:40 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/03 18:59:18 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check if each walls have only one face

static int	check_if_too_much_walls_lines(int *check, t_data *data)
{
	if (check[0] != 1 || check[1] != 1 || check[2] != 1 || check[3] != 1)
		ft_exit_parsing(data, ERROR_WALLS_NUMBERS);
	return (EXIT_SUCCESS);
}

// check here if the 1st arg is a /n
// if the 3rd letter is a valid one
// check if the path exist and is the walls exist.

static int	check_if_direction_if_good(t_data *data, int i, char *face_wall)
{
	if (ft_strncmp(data->map_info->file_cub[i], face_wall, 2))
		return (EXIT_FAILURE);
	if (data->map_info->file_cub[i][2] != ' '
		&& data->map_info->file_cub[i][2] != '\t')
		ft_exit_parsing(data, ERROR_WALLS_WRONG_3RD_LETTER);
	check_and_add_path_walls(data, i, face_wall);
	return (EXIT_SUCCESS);
}

static int	loop_check_face_walls(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map_info->cubfile_number_lines)
	{
		// if (data->map_info->file_cub[0][0] == 0)
		// {
		// 	printf("PROUT_debug\n");
		// 	continue ;
		// }
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
	ft_memset(data->sprites->check, 0, sizeof (int) * 4);
	loop_check_face_walls(data);
	check_if_too_much_walls_lines(data->sprites->check, data);
	return (EXIT_SUCCESS);
}
