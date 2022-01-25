/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:58:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/24 20:24:57 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	*data;

	check_input(ac, av);
	data = init_data();
	if (!data)
		return (EXIT_FAILURE);
	check_input(ac, av);
	if (!get_map(data, av[1]))
		return (EXIT_FAILURE);
	raycasting(data);
	init_controls(data);
	mlx_loop(data->mlx->ptr);
	free_data(data);
	return (EXIT_SUCCESS);
}

// check input / map
// init data
// parse mapcheck input / map
// init data
// parse map
