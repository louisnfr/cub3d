/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:36 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 14:59:14 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// On check si la premiere et derniere lettres sont des 1 sur chaque ligne
// On check si on a bien que des lettres autorise 0 1 E W N S
// On check si E W N S est present une seule fois

static int	check_errors_map(t_data *data)
{
	if (check_error_1st_letter_last_letter(data->map_info->map))
		return (EXIT_FAILURE);
	if (check_if_letters_are_good(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// On check si la map est bien a la fin du fichier et on la stock

static int	check_and_store_map(t_data *data)
{
	if (map_if_in_good_place(data->map_info))
		return (EXIT_FAILURE);
	if (store_data_map(data->map_info))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// on appel toutes les fonctions de parsing/errors de la map ici

int	parsing_map(t_data *data)
{
	if (check_and_store_map(data))
		return (EXIT_FAILURE);
	if (check_errors_map(data))
		return (EXIT_FAILURE);
	if (check_map_is_valid(data))
		return (EXIT_FAILURE);
	data->map_info->map_valid = 1;
	return (EXIT_SUCCESS);
}
