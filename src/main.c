/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:58:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 15:45:16 by lraffin          ###   ########.fr       */
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
		//if (check_if_ber(av))
			//return (0);
		data->mlx_ptr = mlx_init();
		if (!data->mlx_ptr)
			return (MLX_ERROR);
		get_map(data, av);
		//if (check_errors(data, &data->map_lst) == 1)
			//return (0);;
		affichage_game(data);
		return (EXIT_SUCCESS);
	}
	else
		printf("error: bad arguments\n");
	return (EXIT_FAILURE);
}
