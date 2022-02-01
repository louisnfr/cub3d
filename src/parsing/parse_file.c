/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:09 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/01 15:15:18 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check if the parsing went well

static int	check_if_all_file_is_good(t_data *data)
{
	if (data->map_info->floor_ceiling_valid != 1
		&& data->map_info->walls_valid != 1
		&& data->map_info->map_invalid != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_file(t_data *data)
{
	if (parsing_walls(data))
		return (FAILURE);
	if (add_img_wall_to_mlx(data))
	{
		error_message_walls();
		return (FAILURE);
	}
	if (parsing_floor_ceiling(data))
		return (FAILURE);
	if (parsing_map(data))
	{
		error_message_walls();
		return (FAILURE);
	}
	if (check_if_all_file_is_good(data))
		return (FAILURE);
	return (SUCCESS);
}
