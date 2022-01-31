/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:55:43 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 14:55:44 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check de tous les murs

int	parsing_walls(t_data *data)
{
	if (check_all_directions(data))
		return (EXIT_FAILURE);
	data->map_info->walls_valid = 1;
	return (EXIT_SUCCESS);
}
