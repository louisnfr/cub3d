#ifndef STRUCTS_H
# define STRUCTS_H

# include "parsing.h"
# include "player.h"

// struct for our mlx

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*buf1;
	int		bpp;
	int		length;
	int		endian;
	int		x;
	int		y;
	int		*add;
}	t_mlx;

// initial structure

typedef struct s_data
{
	struct s_player		*player;
	struct s_move		*move;
	t_mlx				*mlx;
	struct s_mouse		*mouse;
	struct s_map		*map_info;
	struct s_sprites	*sprites;
	struct s_textures	*textures;
	struct s_minimap	minimap;
	struct s_doors		doors;
	struct s_ray		ray;
	struct s_ray_b		ray_b;
}	t_data;

#endif
