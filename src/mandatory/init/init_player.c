/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:37:03 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/06 17:39:00 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mouse(t_mouse *mouse)
{
	mouse->mb_is_pressed = FALSE;
	mouse->lb_is_pressed = FALSE;
	mouse->rb_is_pressed = FALSE;
	mouse->x = 0;
	mouse->y = 0;
	mouse->old_x = 0;
	mouse->old_y = 0;
}

static	void	set_player_plan(t_player *player, double px, double py)
{
	player->camera.px = px;
	player->camera.py = py;
}

static	void	set_player_direction(t_player *player, double dx, double dy,
									double dz)
{
	player->vector.dz = dz;
	player->vector.dx = dx;
	player->vector.dy = dy;
}

/*
Set up of the player start if the FOV(plan) is negative it will show
a reverse map.
- Dx is for the height of the map (N or S) with 1 it looks to the East with
-1 it looks to the west
- Dy is for the width of the map (E or W) with 1 it looks to the North with
-1 it looks to the East
*/

void	set_player_dir(t_player *player, t_data *data)
{
	if (data->map_info->init_position == 'N')
	{
		set_player_direction(player, 0, -1 , 0);
		set_player_plan(player, 0.66, 0);
	}
	if (data->map_info->init_position == 'S')
	{
		set_player_direction(player, 0, 1, 0);
		set_player_plan(player, -0.66, 0);
	}
	if (data->map_info->init_position == 'E')
	{
		set_player_direction(player, 1, 0, 0);
		set_player_plan(player, 0, 0.66);
	}
	if (data->map_info->init_position == 'W')
	{
		set_player_direction(player, -1, 0, 0);
		set_player_plan(player, 0, 0.66);
	}
}
