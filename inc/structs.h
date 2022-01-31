/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:12:07 by lraffin           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/31 03:59:10 by lraffin          ###   ########.fr       */
=======
/*   Updated: 2022/01/31 13:54:02 by vbachele         ###   ########.fr       */
>>>>>>> error
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_color
{
	char	*raw;
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_map
{
<<<<<<< HEAD
	char	**tab;
	int		w;
	int		h;
}	t_map;
=======
	char			**map;
	char			**file_cub;
	char			*color_ceiling;
	char			*color_floor;
	int				cubfile_number_lines;
	int				cubfile_width_line;
	int				walls_valid;
	int				floor_ceiling_valid;
	int				floor_ceiling_invalid;
	int				walls_invalid;
	int				map_invalid;
	int				map_valid;
	int				first_line;
	int				last_line;
	int				map_width_line;
	int				ceiling_floor[2];
}	t_map;

typedef	struct s_img
{
	void			*img;
	char			*path_img;
	char			*path_face;
	int				width;
	int				height;
} t_img;
>>>>>>> error

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
<<<<<<< HEAD
=======
	int 	check[4];
	t_color ceiling_color;
	t_color floor_color;
	t_img	wall_no;
	t_img	wall_so;
	t_img	wall_we;
	t_img	wall_ea;
>>>>>>> error
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
<<<<<<< HEAD
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
=======
	int fov;

>>>>>>> error
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
