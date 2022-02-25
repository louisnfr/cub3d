/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:15:14 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/25 17:49:09 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* struct for ceiling && floor */

typedef struct s_color
{
	char	*raw;
	int		r;
	int		g;
	int		b;
	int		hex_color;
}	t_color;

/* struct to parse and store the file && map */

typedef struct s_map
{
	char	**map;
	char	**file_cub;
	char	init_position;
	int		x_init;
	int		y_init;
	char	*color_ceiling;
	char	*color_floor;
	int		cubfile_number_lines;
	int		cubfile_width_line;
	int		first_line;
	int		last_line;
	int		map_width_line;
	int		ceiling_floor[2];
}	t_map;

/* struct to store the xmp for the texture */

typedef struct s_img
{
	void	*img;
	char	*path_img;
	char	*path_face;
	int		*tex;
	int		width;
	int		height;
}	t_img;

/* struct for textures */

typedef struct s_textures
{
	int		check[4];
	t_color	ceiling_color;
	t_color	floor_color;
	t_img	wall_no;
	t_img	wall_so;
	t_img	wall_we;
	t_img	wall_ea;
	t_img	doors;
	t_img	doors_open;
	t_img	floor;
	t_img	ceiling;
}	t_textures;

/* struct to draw the texture */

typedef struct s_tex
{
	double	pos;
	t_dir	wall_dir;
	int		line_height;
	int		start;
	int		end;
}	t_tex;

/* struct to open && close the doors */

typedef struct s_doors
{
	int		x;
	int		y;
	int		j;
	t_bool	door_open;
}	t_doors;

/* struct for the mini_map */

typedef struct s_minimap
{
	int	x;
	int	y;
	int	length_x;
	int	length_y;
	int	offset;
}	t_minimap;

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
