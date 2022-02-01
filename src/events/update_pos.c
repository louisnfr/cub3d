/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:15:07 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/01 17:20:56 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_pos(t_data *data)
{
	if (data->move->x || data->move->y)
		move_player(data);
	if (data->move->lateral_x || data->move->lateral_y)
		move_player(data);
	if (data->move->dirx || data->move->diry)
		orient_player(&data->player->camera, &data->player->vector, data);
}
