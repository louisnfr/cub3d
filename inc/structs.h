/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:12:07 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/25 19:31:27 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char			**map;
	char			**file_cub;
	char			*color_ceiling;
	char			*color_floor;
	int				cubfile_number_lines;
	int				cubfile_width_line;
	int				width;
	int				height;
	int				walls_valid;
	int				floor_ceiling_valid;
}	t_map;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*wall_no;
	void	*wall_so;
	void	*wall_we;
	void	*wall_ea;
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
