/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:12:07 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/27 15:41:54 by lraffin          ###   ########.fr       */
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

} t_sprites;

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
	char	mb_is_pressed;
	char	lb_is_pressed;
	char	rb_is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_plane
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_plane;

typedef struct s_data
{
	int			player_x;
	int			player_y;
	int			i;
	int			j;
	int			x;
	int			y;
	// t_ray		*ray;
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
