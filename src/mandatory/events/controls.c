/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:23:25 by lraffin           #+#    #+#             */
/*   Updated: 2022/03/02 13:56:41 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press(int key, t_data *data)
{
	// printf("pressed: %d\n", key);
	if (key == W)
		data->move->x = TRUE;
	if (key == S)
		data->move->y = TRUE;
	if (key == A)
		data->move->lateral_x = TRUE;
	if (key == D)
		data->move->lateral_y = TRUE;
	if (key == RIGHT)
		data->move->dirx = TRUE;
	if (key == LEFT)
		data->move->diry = TRUE;
	if (key == SHIFT)
		data->move->shift = TRUE;
	if (key == M)
		data->move->minimap = TRUE; // bonus
	if (key == F && data->sprite_f[7].sprite_die == FALSE
		&& data->sprite_f[7].is_seen == TRUE
		&& data->sprites->weapon.weapon_on == TRUE)
	{
		//data->sprite_f[7].number_attack++;
		play_sound(saber_1, 80);
		data->move->attack = TRUE; // bonus
	}
	else if (key == F && data->sprite_f[8].sprite_die == FALSE
		&& data->sprite_f[8].is_seen == TRUE
		&& data->sprites->weapon.weapon_on == TRUE)
	{
		play_sound(saber_1, 80);
		data->move->attack = TRUE;
	}
	else if (key == F && data->sprite_f[12].sprite_die == FALSE
			&& data->sprite_f[12].is_seen == TRUE
			&& data->sprites->weapon.weapon_on == TRUE)
	{
		play_sound(saber_1, 80);
		data->move->attack = TRUE;
	}
	else if (key == F && data->sprites->weapon.weapon_on == TRUE)
	{
		play_sound(saber_1, 80);
		data->move->attack = TRUE;
	}
	return (SUCCESS);
}

static int	key_release(int key, t_data *data)
{
	if (key == ESC)
		exit_all(data);
	if (key == W)
		data->move->x = FALSE;
	if (key == S)
		data->move->y = FALSE;
	if (key == A)
		data->move->lateral_x = FALSE;
	if (key == D)
		data->move->lateral_y = FALSE;
	if (key == RIGHT)
		data->move->dirx = FALSE;
	if (key == LEFT)
		data->move->diry = FALSE;
	if (key == SHIFT)
		data->move->shift = FALSE;
	if (key == M)
		data->move->minimap = FALSE; // bonus
	if (key == F
		&& data->sprites->weapon.weapon_on == TRUE
		&& data->sprite_f[7].is_seen == TRUE)
	{
		sleep(1);
		play_sound(saber_2, 80);
		//data->sprite_f[7].number_attack++;
		//printf("PROUT_debug %d\n", data->sprite_f[7].number_attack);
		data->move->attack = FALSE; // bonus
	}
	else if (key == F && data->sprite_f[8].sprite_die == TRUE
		&& data->sprite_f[8].is_seen == TRUE
		&& data->sprites->weapon.weapon_on == TRUE)
	{
		play_sound(saber_2, 80);
		sleep(1);
		data->move->attack = FALSE;
	}
	else if (key == F && data->sprite_f[12].sprite_die == TRUE
			&& data->sprite_f[12].is_seen == TRUE
			&& data->sprites->weapon.weapon_on == TRUE)
	{
		play_sound(saber_2, 80);
		sleep(1);
		data->move->attack = FALSE;
	}
	else if (key == F && data->sprites->weapon.weapon_on == TRUE)
	{
		play_sound(saber_2, 80);
		//printf("PROUT_debug_3\n");
		data->move->attack = FALSE;
	}
	return (SUCCESS);
}

/*** For the bonus
***/

void	init_controls(t_data *data)
{
	data->move->minimap = FALSE;
	data->mouse = malloc(sizeof(t_mouse));
	init_mouse(data->mouse);
	mlx_mouse_hide(data->mlx->ptr, data->mlx->win);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx->win, 33, 1L << 2, exit_all, data);
}
