/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:31:08 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/25 15:35:20 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_data *data)
{
	data->mlx = NULL;
	ft_memset(data->map_info, 0, sizeof(t_map));
	ft_memset(data->textures, 0, sizeof(t_textures));
}

t_move	*init_move(t_data *data)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (!move)
		ft_exit_parsing(data, MALLOC);
	ft_memset(move, 0, sizeof(t_move));
	return (move);
}

t_mlx	*init_mlx(t_data *data)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		ft_exit_parsing(data, MALLOC);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIN_W, WIN_H, "cub3d");
	mlx->img = mlx_new_image(mlx->ptr, WIN_W, WIN_H);
	mlx->buf1 = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->length, &mlx->endian);
	return (mlx);
}

t_player	*init_player(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		ft_exit_parsing(data, MALLOC);
	player->vector.x = data->map_info->x_init + 0.5;
	player->vector.y = data->map_info->y_init + 0.5;
	set_player_dir(player, data);
	return (player);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->textures = malloc(sizeof(t_textures));
	data->mouse = malloc(sizeof(t_mouse));
	data->map_info = malloc(sizeof(t_map));
	if (!data || !data->textures || !data->map_info || !data->mouse)
		ft_exit_parsing(data, MALLOC);
	data->move = init_move(data);
	return (data);
}
