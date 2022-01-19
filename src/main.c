/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:58:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/19 16:23:04 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = init_data();
		if (!data)
			return (EXIT_FAILURE);
		if (!get_map(data, av[1]))
			return (EXIT_FAILURE);
		
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
