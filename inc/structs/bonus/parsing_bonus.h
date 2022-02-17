#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

/*** struct to open && close the doors ***/

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

typedef	struct s_sprite_f
{
	char	**arg_sprite;
	double	x;
	double	y;
	int		*tex;
	char	*path;
	char	*name;
	double	spritex;
	double	spritey;
	t_bool	sprites_die;
	// void	*img;
} t_sprite_f;


#endif