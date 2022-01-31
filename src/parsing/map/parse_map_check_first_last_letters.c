/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check_first_last_letters.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:24 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 14:59:56 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	check_error_last_letter(char **map)
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
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static	int	check_error_first_letter(char **map)
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
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

// check 1st and last letter of the line

int	check_error_1st_letter_last_letter(char **map)
{
	int	len;

	len = 0;
	if (check_error_first_letter(map))
		return (EXIT_FAILURE);
	if (check_error_last_letter(map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
