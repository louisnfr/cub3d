/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check_letters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:55:18 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/28 16:32:57 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check if we have only one beginning face for the player

static	int	check_error_initial_position_player(char **map,
		char initial_position, t_map *map_info)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == initial_position)
			{
				map_info->init_position = initial_position;
				map_info->x_init = j;
				map_info->y_init = i;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static	int	letters_are_more_than_once(char **map, t_map *map_info)
{
	int	count;

	count = 0;
	count = count + check_error_initial_position_player(map, 'W', map_info);
	count = count + check_error_initial_position_player(map, 'E', map_info);
	count = count + check_error_initial_position_player(map, 'N', map_info);
	count = count + check_error_initial_position_player(map, 'S', map_info);
	if (count != 1)
		return (SUCCESS);
	return (FAILURE);
}

static	int	check_letters_map(char letter)
{
	if (letter == '1' || letter == '2' || letter == '3')
		return (FAILURE);
	else if (letter == '0')
		return (FAILURE);
	else if (letter == ' ')
		return (FAILURE);
	else if (letter == '\t')
		return (FAILURE);
	else if (letter == 'N')
		return (FAILURE);
	else if (letter == 'S')
		return (FAILURE);
	else if (letter == 'W')
		return (FAILURE);
	else if (letter == 'E')
		return (FAILURE);
	return (SUCCESS);
}

static	int	check_all_the_letters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_letters_map(map[i][j]))
				return (SUCCESS);
			j++;
		}
		i++;
	}
	return (FAILURE);
}

/*
Check if other letters than authorized
 Check if Starting position player is > 0
*/

int	check_if_letters_are_good(t_data *data)
{
	if (check_all_the_letters(data->map_info->map))
		ft_exit_parsing(data, MAP_UNAUTHORIZED_LETTER);
	if (letters_are_more_than_once(data->map_info->map, data->map_info))
		ft_exit_parsing(data, MAP_TOO_MUCH_PLAYER);
	return (FAILURE);
}
