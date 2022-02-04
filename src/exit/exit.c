#include "cub3d.h"

int	ft_exit_parsing(t_data *data, char *error_message)
{
	ft_error_message(error_message);
	free_data(data);
	exit(1);
}

int	exit_all(t_data *data)
{
	free_data(data);
	exit(EXIT_SUCCESS);
	return (1);
}