/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:49:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/24 14:34:22 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_data(t_data *data)
{
	free_double_str(data->map_info->map);
	free(data->sprites);
	free(data->map_info);
	mlx_destroy_display(data->mlx->ptr);
	free(data->mlx->ptr);
	free(data);
	// mlx_destroy_window(data->mlx->ptr, data->mlx->win_ptr);
	return (EXIT_SUCCESS);
}

int	free_all_functions(t_data *data)
{
	if (data->sprites)
		free(data->sprites);
	// if (data->map_info)
	// 	ft_lstclear(&data->map_info, del_content);
	free_double_tableau(data);
	mlx_destroy_window(data->mlx->ptr, data->mlx->win_ptr);
	if (data)
		free(data);
	free(data->mlx->ptr);
	exit(1);
}

// void	del_content(t_map **map_info)
// {
// 	free((*map_info)->line);
// 	(*map_info)->line = NULL;
// }

void	free_double_tableau(t_data *data)
{
	int	i;

	i = -1;
	while (data->map_info->map[++i])
		free(data->map_info->map[i]);
	free(data->map_info->map);
}
