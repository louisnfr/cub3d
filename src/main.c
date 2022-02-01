#include "cub3d.h"

static int	main_loop(t_data *data)
{
	if (data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	data->mlx->img = mlx_new_image(data->mlx->ptr, WIN_W, WIN_H);
	data->mlx->buf1 = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
			&data->mlx->length, &data->mlx->endian);
	update_pos(data);
	raycasting(data->player, data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win,
		data->mlx->img, 0, 0);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	*data;

	check_input(ac, av);
	data = init_data();
	init_struct(data);
	if (!data)
	{
		free_data(data);
		return (EXIT_FAILURE);
	}
	if (!get_file(data, av[1]))
	{
		free_data(data);
		return (EXIT_FAILURE);
	}
	if (!parse_file(data))
	{
		free_data(data);
		return (EXIT_FAILURE); // pensez a free le double tableau
	}
	data->player = init_player(data);
	init_controls(data);
	mlx_loop_hook(data->mlx->ptr, main_loop, data);
	mlx_loop(data->mlx->ptr);
	free_data(data);
	return (EXIT_SUCCESS);
}
