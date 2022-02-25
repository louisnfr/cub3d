/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:33:51 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/25 16:33:59 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	check_minimap(t_data *data, t_map *map)
{
	if (map->map[data->minimap.y][data->minimap.x] == 'N'
				|| map->map[data->minimap.y][data->minimap.x] == 'S'
				|| map->map[data->minimap.y][data->minimap.x] == 'W'
				|| map->map[data->minimap.y][data->minimap.x] == 'E')
		return (1);
	return (0);
}
