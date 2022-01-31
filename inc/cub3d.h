/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:12:00 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 04:05:09 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs.h"

/*** init ***/

t_data	*init_data(void);
void	init_mouse(t_mouse *mouse);

/*** parsing ***/

void	check_input(int ac, char **av);
int		get_map(t_data *data, char *av);

/*** raycasting ***/

int		raycasting(t_player *player, t_data *data);

/*** events ***/

void	init_controls(t_data *data);

/*** display ***/

void	put_pixel(int x, int y, int color, t_mlx *mlx);
void	put_vline(int x, t_point b, int color, t_mlx *mlx);

/*** exit ***/

int		free_data(t_data *data);

#endif
