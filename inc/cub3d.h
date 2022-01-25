/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:12:00 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/25 15:47:02 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define	CUBE_3D_H

# include "libs.h"

/*** init ***/

t_data	*init_data(void);
void	init_mouse(t_mouse *mouse);

/*** parsing ***/

void	check_input(int ac, char **av);

/*** raycasting ***/

int		precalculate_rays(t_data *data);

/*** events ***/

void	init_controls(t_data *data);

/*** display ***/

void	put_pixel(int x, int y, int color, t_mlx *mlx);
void	put_vline(int x, t_point b, int color, t_mlx *mlx);

int		raycasting(t_data *data);
int		get_map(t_data *data, char *av);


void	display_sprites2(t_data *data);
void	display_sprites(t_data *data);
void	create_sprites(t_data *data);
int		create_and_display_sprites(t_data *data);

/*** exit ***/

int	free_data(t_data *data);

void	del_content(t_map **map_info);
void	free_double_tableau(t_data *data);
int		free_all_functions(t_data *data);

#endif
