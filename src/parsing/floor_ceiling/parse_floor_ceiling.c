/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:19 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 14:56:20 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing_floor_ceiling(t_data *data)
{
	if (check_if_floor_ceiling_exist(data))
		return (EXIT_FAILURE);
	data->map_info->floor_ceiling_valid = 1;
	return (EXIT_SUCCESS);
}
