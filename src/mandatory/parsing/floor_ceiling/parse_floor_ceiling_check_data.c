/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling_check_data.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:14 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/04 12:09:36 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//check if ceiling_floor_is_invalid

static int	error_number_ceiling_floor(t_map *map_info, t_data *data)
{
	if (map_info->ceiling_floor[0] != 1 || map_info->ceiling_floor[1] != 1)
		ft_exit_parsing(data, ERROR_CEILING_FLOOR_WRONG_NUMBER_LINES);
	return (FAILURE);
}

// check 1st letter and check if not duplicated C or F + go to the file color

static int	check_if_ceiling_floor_if_good(t_data *data, int i,
	char *ceiling_or_floor, int *check)
{
	if (ft_strncmp(data->map_info->file_cub[i], ceiling_or_floor, 1))
		return (SUCCESS);
	if (data->map_info->file_cub[i][1] != ' '
		&& data->map_info->file_cub[i][1] != '\t')
		ft_exit_parsing(data, ERROR_CEILING_FLOOR_WRONG_2ND_LETTERS);
	(*check)++;
	if ((*check) == 2)
		ft_exit_parsing(data, ERROR_CEILING_FLOOR_CALLED_TOO_MANY);
	check_and_add_color_ceiling_floor(data, i);
	return (FAILURE);
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
	if (error_number_ceiling_floor(data->map_info, data))
		return (SUCCESS);
	return (FAILURE);
}
