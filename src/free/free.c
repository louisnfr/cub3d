/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:49:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 16:33:55 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_all_functions(t_data *data)
{
	if (data->sprites)
		free(data->sprites);
	// if (data->map_info)
	// 	ft_lstclear(&data->map_info, del_content);
	free_double_tableau(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data)
		free(data);
	free(data->mlx_ptr);
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
