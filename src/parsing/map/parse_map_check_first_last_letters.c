/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check_first_last_letters.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:24 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/03 16:49:23 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	check_error_last_letter(char **map, t_data *data)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]) - 1;
		while (map[i][len] == ' ' || map[i][len] == '\t')
			len--;
		if (map[i][len] != '1')
			ft_exit_parsing(data, ERROR_MAP_LAST_LETTER);
		i++;
	}
	return (EXIT_SUCCESS);
}

static	int	check_error_first_letter(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] != '1')
			ft_exit_parsing(data, ERROR_MAP_FIRST_LETTER);
		i++;
	}
	return (EXIT_SUCCESS);
}

// check 1st and last letter of the line

int	check_error_1st_letter_last_letter(char **map, t_data *data)
{
	check_error_first_letter(map, data);
	check_error_last_letter(map, data);
	return (EXIT_SUCCESS);
}
