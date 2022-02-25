/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:34:07 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/25 17:55:29 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
check the number of times we see the element c
*/

int	ft_strlen_double_str_find_element(char **double_str, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (double_str[i])
	{
		j = 0;
		while (double_str[i][j])
		{
			if (double_str[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	init_bonus_struct(t_data *data)
{
	ft_memset(&data->ray_b, 0, sizeof(t_ray_b));
}

/*
init and store the data for the doors
*/

int	store_data_bonus(t_map *map, t_data *data)
{
	(void)map;
	ft_memset(&data->doors, 0, sizeof(t_doors));
	data->doors.door_open = FALSE;
	return (SUCCESS);
}

int	check_minimap(t_data *data, t_map *map)
{
	if (map->map[data->minimap.y][data->minimap.x] == 'N'
				|| map->map[data->minimap.y][data->minimap.x] == 'S'
				|| map->map[data->minimap.y][data->minimap.x] == 'W'
				|| map->map[data->minimap.y][data->minimap.x] == 'E')
		return (1);
	return (0);
}
