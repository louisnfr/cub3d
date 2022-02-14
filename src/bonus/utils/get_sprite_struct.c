#include "cub3d.h"

char	**put_sprite_in_struct(t_data *data, char *arg_sprite)
{
	char	**parsing;

	parsing = NULL;
	parsing = ft_split(arg_sprite, 32);
	if (!parsing)
		ft_exit_parsing(data,"Error\n"
			"Problem with your memory_allocation\n");
	return (parsing);
}