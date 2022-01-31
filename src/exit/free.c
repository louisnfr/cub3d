/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:49:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 04:04:53 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_data(t_data *data)
{
	free_double_str(data->map->tab);
	free(data->sprites);
	free(data->map);
	free(data->mlx->ptr);
	free(data);
	return (EXIT_SUCCESS);
}
