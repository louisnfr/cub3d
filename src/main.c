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
	if (parse_file(data))
	{
		free_data(data);
		return (EXIT_FAILURE); // pensez a free le double tableau
	}
	printf("TOUT EST OK\n");
	// precalculate_rays(data);
	// init_controls(data);
	// mlx_loop(data->mlx->ptr);
	free_data(data);
	return (EXIT_SUCCESS);
}
