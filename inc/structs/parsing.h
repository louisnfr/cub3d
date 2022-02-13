#ifndef PARSING_H
# define PARSING_H

// struct for the doors

typedef struct s_doors
{
	int		x;
	int		y;
	int		j;
	t_bool	door_open;
} t_doors;


// struct for the mini_map

typedef	struct s_minimap
{
	int	x;
	int	y;
	int	length_x;
	int	length_y;
	int	offset;
}	t_minimap;

// struct for ceiling && floor

typedef struct s_color
{
	char	*raw;
	int		r;
	int		g;
	int		b;
	int		hex_color;
}	t_color;

// struct to parse and store the file && map

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

// struct to store the xmp for the texture

typedef struct s_img
{
	void	*img;
	char	*path_img;
	char	*path_face;
	int		*tex;
	int		width;
	int		height;
}	t_img;

// struct for textures

typedef	struct s_textures
{
	int		check[4];
	t_color	ceiling_color;
	t_color	floor_color;
	t_img	wall_no;
	t_img	wall_so;
	t_img	wall_we;
	t_img	wall_ea;
	t_img	doors;
	t_img	floor;
	t_img	ceiling;
} t_textures;

// struct to display the sprites

typedef struct s_sprites
{
	void		*mini_map_blank;
	void		*wall;
	void		*floor;
	t_img		barrel;
	double		x;
	double		y;
	double		zbuffer[WIN_W];
	int			sprite_order[NUM_SPRITE];
	double		sprite_distance[NUM_SPRITE];
	double		spritex;
	double		spritey;
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
	u_int32_t 	buffer[WIN_H][WIN_W];
}	t_sprites;

// struct to draw the texture

typedef struct s_tex
{
	double	pos;
	t_dir	wall_dir;
	int		line_height;
	int		start;
	int		end;
}	t_tex;

#endif
