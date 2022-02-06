#ifndef STRUCTS_H
# define STRUCTS_H

# include "parsing.h"
# include "player.h"

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*buf1;
	char	*buf2;
	int		bpp;
	int		length;
	int		endian;
	int		x;
	int		y;
	int		*add;
}	t_mlx;

typedef struct s_data
{
	struct s_player		*player;
	struct s_move		*move;
	t_mlx				*mlx;
	struct s_mouse		*mouse;
	struct s_map		*map_info;
	struct s_sprites	*sprites;
}	t_data;

#endif
