#ifndef STRUCTS_H
# define STRUCTS_H

# include "parsing.h"
# include "player.h"
# include "bonus/player_bonus.h"
# include "bonus/parsing_bonus.h"
# include "bonus/sprites.h"

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
	struct s_player			*player;
	struct s_move			*move;
	t_mlx					*mlx;
	struct s_mouse			*mouse;
	struct s_map			*map_info;
	struct s_sprites		*sprites;
	struct s_textures		*textures;
	struct s_minimap		minimap;
	struct s_doors			doors;
	struct s_ray			ray;
	struct s_ray_b			ray_b;
	struct s_sprite_f	sprite_f;
}	t_data;

#endif
