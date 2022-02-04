/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:36 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/04 12:09:21 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// On check si la premiere et derniere lettres sont des 1 sur chaque ligne
// On check si on a bien que des lettres autorise 0 1 E W N S
// On check si E W N S est present une seule fois

static int	check_errors_map(t_data *data)
{
	check_error_1st_letter_last_letter(data->map_info->map, data);
	check_if_letters_are_good(data);
	return (FAILURE);
}

// on appel toutes les fonctions de parsing/errors de la map ici

int	parsing_map(t_data *data)
{
	map_if_in_good_place(data->map_info, data);
	store_data_map(data->map_info, data);
	check_errors_map(data);
	check_map_is_valid(data);
	return (FAILURE);
}
