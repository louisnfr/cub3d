#include "cub3d.h"

void	free_sprites(t_data *data)
{
	int i;

	i = 0;
	while (i < data->sprites->num_sprites)
	{
		if (data->sprite_f[i].tex)
			free(data->sprite_f[i].tex);
		i++;
	}
}

void free_bonus_textures(t_data *data, t_textures *textures)
{
	free(textures->doors.tex);
	free(textures->doors_open.tex);
	free(textures->ceiling.tex);
	free(textures->floor.tex);
	free_double_str(data->sprites->arg_sprite);
	if (textures->doors.img)
		mlx_destroy_image(data->mlx->ptr, textures->doors.img);
	if (textures->doors_open.img)
		mlx_destroy_image(data->mlx->ptr, textures->doors_open.img);
	if (textures->ceiling.img)
		mlx_destroy_image(data->mlx->ptr, textures->ceiling.img);
	if (textures->floor.img)
		mlx_destroy_image(data->mlx->ptr, textures->floor.img);
}