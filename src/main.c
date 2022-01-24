/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:58:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/24 19:27:30 by lraffin          ###   ########.fr       */
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
	t_point a = {15, 15};
	t_point b = {150, 150};
	if (data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	data->mlx->img = mlx_new_image(data->mlx->ptr, WIDTH, HEIGHT);
	data->mlx->buf1 = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
			&data->mlx->length, &data->mlx->endian);
	put_line(a, b, RED, data->mlx);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	// raycasting(data);
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
