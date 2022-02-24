/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:16:19 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/24 16:15:24 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	dx;
	double	dy;
}	t_vector;

typedef struct s_camera
{
	double	px;
	double	py;
}	t_camera;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_player
{
	t_vector	vector;
	t_camera	camera;
}	t_player;

typedef struct s_ray
{
	double	dirx;
	double	diry;
	double	deltax;
	double	deltay;
	double	distx;
	double	disty;
	double	pw;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
}	t_ray;

typedef struct s_mouse
{
	int		x;
	int		y;
	int		old_x;
	int		old_y;
	char	mb_is_pressed;
	char	lb_is_pressed;
	char	rb_is_pressed;
}	t_mouse;

typedef struct s_move
{
	t_bool	x;
	t_bool	y;
	t_bool	z;
	t_bool	lateral_x;
	t_bool	lateral_y;
	t_bool	dirx;
	t_bool	diry;
	t_bool	dirz;
	t_bool	shift;
	t_bool	minimap;
}	t_move;

#endif
