#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	*data;

	check_input(ac, av);
	data = init_data();
	if (!data)
		return (EXIT_FAILURE);
	if (!get_file(data, av[1]))
		return (EXIT_FAILURE);
	if (parse_file(data))
		return (EXIT_FAILURE); // pensez a free le double tableau 
	// precalculate_rays(data);
	init_controls(data);
	mlx_loop(data->mlx->ptr);
	free_data(data);
	return (EXIT_SUCCESS);
}
