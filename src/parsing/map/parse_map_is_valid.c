/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_is_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:55:29 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/03 17:48:10 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//On check si a l'interieur de la map si il y a un zero ou pas

static	int	check_coordinate(char coordinate)
{
	if (coordinate == ' ')
		return (EXIT_FAILURE);
	else if (coordinate == '\t')
		return (EXIT_FAILURE);
	else if (coordinate == '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int	check_zero_and_player_good_place(char letter,
											int y, int x, t_data *data)
{
	char	**map;

	map = data->map_info->map;
	if (letter == '0' || letter == 'W' || letter == 'S'
		|| letter == 'E' || letter == 'N')
	{
		if (check_coordinate(map[y - 1][x])
			|| check_coordinate(map[y + 1][x])
			|| check_coordinate(map[y][x + 1])
			|| check_coordinate(map[y][x - 1]))
		{
			ft_exit_parsing(data, ERROR_MAP_PROBLEM_INSIDE_WALLS);
		}
	}
	return (EXIT_SUCCESS);
}

int	check_map_is_valid(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map_info->map;
	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			check_zero_and_player_good_place(map[i][j], i, j, data);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
