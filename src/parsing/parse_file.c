/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:46:00 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/28 16:33:16 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
check if the parsing went well
*/

int	parse_file(t_data *data)
{
	parsing_walls(data);
	parsing_floor_ceiling(data);
	parsing_map(data);
	return (SUCCESS);
}
