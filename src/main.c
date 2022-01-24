/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:58:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/24 22:09:08 by lraffin          ###   ########.fr       */
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
	if (!get_map(data, av[1]))
		return (EXIT_FAILURE);

	precalculate_rays(data);
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
