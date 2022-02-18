/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:17:45 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/18 15:17:49 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

/* struct for the ray_bonus to put texture on floor and ceiling */

typedef struct s_ray_b
{
	double		dirx0;
	double		dirx1;
	double		diry0;
	double		diry1;
	int			p;
	double		posz;
	double		rowdistance;
	double		floorstepx;
	double		floorstepy;
	double		floorx;
	double		floory;
	int			cellx;
	int			celly;
	int			tx;
	int			ty;
	u_int32_t	buffer[WIN_H][WIN_W];
}	t_ray_b;

#endif
