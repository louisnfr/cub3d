#include "cub3d.h"


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
 	Function here to load and malloc all the
 	bonus sprite(ceiling, floor, sprites) in xpm
***/

int	cub_load_sprites(t_data *data, t_mlx *mlx, t_sprite_f *sf)
{
	int i;
	char **path;

	i = 0;
	while (i < data->sprites->num_sprites)
	{
		path = NULL;
		cub_init_sprites(data, &data->sprite_f[i]);
		printf("i %d\n", i);
		printf("str %s\n", data->sprites->arg_sprite[i]);
		if (data->sprites->arg_sprite[i] != 0)
			path = put_sprite_in_struct(data, data->sprites->arg_sprite[i]);
		if (path[1])
			cub_load_xpm(mlx, sf[i].tex, path[1]);
		if (path[0])
			sf[i].name = ft_strdup(path[0]);
		if (path[2] != 0)
			sf[i].x = ft_atoi(path[2]); // coordinate x
		if (path[3] != 0)
			sf[i].y = ft_atoi(path[3]); // coordinate y
		free_double_str(path); //free path no need
		i++;
	}
	return (SUCCESS);
}