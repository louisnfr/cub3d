#include "cub3d.h"

/*** give a name to the sprite
	ZW = for XWING
	DVO = DVO Darth Vader opening
	DVF = darthvador using force
	DVM = Darthvader moving
	RB = Rolling Ball
	R2D2 = R2D2
	BOMB = Explosion when dead
***/

static void	name_sprite(t_sprite_f *sf, int i, char **path, t_data *data)
{
	if (!ft_strcmp(path[0], "XW") || !ft_strcmp(path[0], "R2D2")
		|| !ft_strcmp(path[0], "BOMB") || !ft_strcmp(path[0], "LS"))
	{
		data->sprite_f[i].name = ft_strdup(path[0]);
		data->sprite_f[i].is_ennemy = FALSE;
	}
	else if (!ft_strcmp(path[0], "DVO") || !ft_strcmp(path[0], "DVF")
		|| !ft_strcmp(path[0], "DVM") || !ft_strcmp(path[0], "RB"))
	{
		data->sprite_f[i].name = ft_strdup(path[0]);
		data->sprite_f[i].is_ennemy = TRUE;
	}
	else
		ft_exit_parsing(data, "Not the good name for the sprite"
						"in the .sprites_col cub\n");
	//printf("[%d] in function = sf[0].name %s\n", i, sf[i].name);
}

/***
Function to malloc the texture of the xpm in order to load it
***/

static void	cub_init_sprites(t_data *data, t_sprite_f *sp)
{
	int		j;
	sp->tex = (int *)malloc(sizeof(int) * (SPRITE_W * SPRITE_H));
	if (!sp->tex)
		ft_exit_parsing(data, "Error\nMalloc failed\n");
	j = 0;
	while (j < SPRITE_W * SPRITE_H)
	{
		sp->tex[j] = 0;
		j++;
	}
}

/***
 	Function to init and malloc the weapon
***/

void	cub_init_weapon(t_data *data, t_sprite_f *sp)
{
	int j;

	sp->tex = (int *)malloc(sizeof(int) * (WEAPON_W * WEAPON_H));
	if (!sp->tex)
		ft_exit_parsing(data, "Error\nMalloc failed\n");
	j = 0;
	while (j < WEAPON_W * WEAPON_H)
	{
		sp->tex[j] = 0;
		j++;
	}
}

/***
 	Function here to load and malloc all the
 	bonus sprite(ceiling, floor, sprites) in xpm
	The number 1 in the sprite document is the light saber
***/

int	cub_load_sprites(t_data *data, t_mlx *mlx, t_sprite_f *sf)
{
	int		i;
	char	**path;

	i = 0;
	while (i < data->sprites->num_sprites)
	{
		if (i != 1)
			cub_init_sprites(data, &data->sprite_f[i]);
		else
			cub_init_weapon(data, &data->sprite_f[i]);
		if (data->sprites->arg_sprite[i] != 0)
			path = put_sprite_in_struct(data, data->sprites->arg_sprite[i]);
		if (path[0] != 0)
			name_sprite(sf, i, path, data);
		if (path[1] != 0)
			cub_load_xpm(mlx, sf[i].tex, path[1]);
		if (path[2] != 0)
			sf[i].x = ft_atoi(path[2]);
		if (path[3] != 0)
			sf[i].y = ft_atoi(path[3]);
		i++;
	}
	return (SUCCESS);
}
