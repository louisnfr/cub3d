#include "cub3d.h"

/* In this loop we store in buf1 all the map to do the raycasting after.
Continusly we update the screen in the loop.
*/
static int	main_loop(t_data *data)
{
	if (data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	data->mlx->img = mlx_new_image(data->mlx->ptr, WIN_W, WIN_H);
	data->mlx->buf1 = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
			&data->mlx->length, &data->mlx->endian);
	update_pos(data);
	raycasting(data->player, data);
	mini_map(data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win,
		data->mlx->img, 0, 0);
	mini_map(data); // bonus mettre dans une meme fonction
	doors(data); // bonus
	return (SUCCESS);
}

# define PLAYER "aplay"
# define BACKGROUND " &"
# define OPTIONS " > /dev/null 2>&1"

int	play_sound(char *path)
{
	char	command[1000];

	ft_bzero(command);
	ft_strlcat(command, "(" PLAYER " ", 1000);
	ft_strlcat(command, path, 1000);
	ft_strlcat(command, BACKGROUND ") " OPTIONS, 1000);
	return (system(command));
}

int	main(int ac, char **av)
{
	t_data	*data;

	play_sound("r2d2.mp3");
	check_input(ac, av);
	data = init_data();
	init_struct(data);
	init_bonus_struct(data);
	get_file(data, av[1]);
	parse_file(data);
	data->mlx = init_mlx(data);
	add_img_wall_to_mlx(data);
	cub_load_textures(data->mlx, data->textures, data);
	data->player = init_player(data);
	init_controls(data);
	mlx_loop_hook(data->mlx->ptr, main_loop, data);
	mlx_loop(data->mlx->ptr);
	free_data(data);
	return (FAILURE);
}
