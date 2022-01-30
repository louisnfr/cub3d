/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:12:07 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/30 17:39:18 by vbachele         ###   ########.fr       */
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

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	int 	check[4];
	t_color ceiling_color;
	t_color floor_color;
	t_img	wall_no;
	t_img	wall_so;
	t_img	wall_we;
	t_img	wall_ea;
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
	char	mb_is_pressed;
	char	lb_is_pressed;
	char	rb_is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_ray
{
	int fov;

}	t_ray;

typedef struct s_data
{
	int			player_x;
	int			player_y;
	int			i;
	int			j;
	int			x;
	int			y;
	t_ray		*ray;
	t_mlx		*mlx;
	t_mouse		*mouse;
	t_map		*map_info;
	t_sprites	*sprites;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif
