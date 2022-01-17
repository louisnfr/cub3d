/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:58:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 18:42:01 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		//if (check_if_ber(av))
			//return (0);
		data = init_data();
		if (!data)
			return (EXIT_FAILURE);
		if (!get_map(data, av[1]))
			return (EXIT_FAILURE);
		data->mlx_ptr = mlx_init();
		if (!data->mlx_ptr)
			return (MLX_ERROR);
		//if (check_errors(data, &data->map_info) == 1)
			//return (0);
		draw_map(data);
		free_data(data);
		return (EXIT_SUCCESS);
	}
	else
		printf("error: bad arguments\n");
	return (EXIT_FAILURE);
}
// check input / map
// init data
// parse map
//
