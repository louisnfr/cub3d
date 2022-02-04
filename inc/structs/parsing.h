#ifndef PARSING_H
# define PARSING_H

typedef struct s_color
{
	char	*raw;
	int		r;
	int		g;
	int		b;
	int		hex_color;
}	t_color;

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

typedef struct s_img
{
	void	*img;
	char	*path_img;
	char	*path_face;
	int		width;
	int		height;
}	t_img;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	int		check[4];
	t_color	ceiling_color;
	t_color	floor_color;
	t_img	wall_no;
	t_img	wall_so;
	t_img	wall_we;
	t_img	wall_ea;
}	t_sprites;

typedef struct s_tex
{
	double	pos;
	t_dir	wall_dir;
	int		line_height;
	int		start;
	int		end;
}	t_tex;

#endif
