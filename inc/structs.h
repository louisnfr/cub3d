/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:12:07 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/31 03:59:10 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char	**tab;
	int		w;
	int		h;
}	t_map;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
}	t_sprites;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*buf1;
	char		*buf2;
	int			bpp;
	int			length;
	int			endian;
}	t_mlx;

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

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	dx;
	double	dy;
	double	dz;
}	t_vector;

typedef struct s_camera
{
	double	px;
	double	py;
}	t_camera;

typedef struct s_player
{
	t_vector	vector;
	t_camera	camera;
}	t_player;

typedef struct s_data
{
	t_player	*player;
	t_mlx		*mlx;
	t_mouse		*mouse;
	t_map		*map;
	t_sprites	*sprites;
}	t_data;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

#endif
