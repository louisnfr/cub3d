#include "cub3d.h"

int main(int ac, char **av)
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
	printf("PROUT_d234234ebug\n");
	if (parse_file(data))
	{
		free_data(data);
		return (EXIT_FAILURE); // pensez a free le double tableau 
	}
	// if (add_img_wall_to_mlx(data))
	// {
	// 	free_data(data);
	// 	return (EXIT_FAILURE);
	// }
	// precalculate_rays(data);
	init_controls(data);
	mlx_loop(data->mlx->ptr);
	free_data(data);
	return (EXIT_SUCCESS);
}
