/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:09:33 by lraffin           #+#    #+#             */
/*   Updated: 2022/03/06 15:09:33 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

// struct to display the ennemy

typedef struct s_ennemy
{
	t_bool	rolling_b_dead_1;
	t_bool	rolling_b_dead_2;
	t_bool	rolling_b_dead_3;
	t_bool	rolling_b_dead_4;
	t_bool	darth_vader;
	t_bool	stormtrooper;
}	t_ennemy;

typedef struct weapon
{
	t_bool	weapon_on;
}	t_weapon;

typedef struct s_sprites
{
	void		*mini_map_blank;
	void		*wall;
	void		*floor;
	char		**arg_sprite;
	t_img		barrel;
	double		x;
	double		y;
	double		zbuffer[WIN_W];
	int			sprite_order[NUM_SPRITE];
	double		sprite_distance[NUM_SPRITE];
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			spritewidth;
	int			drawstarty;
	int			drawstartx;
	int			drawendy;
	int			drawendx;
	int			texx;
	void		*final;
	int			texy;
	int			num_sprites;
	int			stripe;
	u_int32_t 	buffer[WIN_H][WIN_W];
	t_ennemy	ennemy;
	t_weapon	weapon;
}	t_sprites;

#endif
