/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:12:00 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/30 14:10:58 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define	CUBE_3D_H

# include "libs.h"

/*** init ***/

t_data	*init_data(void);
void	init_struct(t_data *data);
void	init_mouse(t_mouse *mouse);

/*** parsing ***/

char    **ft_split_charset(char *str, char *charset);
void	check_input(int ac, char **av);
int		parse_file(t_data *data);
int		get_map(t_data *data, char *av);
int 	parsing_walls(t_data *data);
int		add_img_wall_to_mlx(t_data *data);
void	error_message_walls(void);
int		check_all_directions(t_data *data);
int		check_and_add_path_walls(t_data *data, int i, char *face_wall);
int		check_if_floor_ceiling_exist(t_data *data);
int		check_and_add_color_ceiling_floor(t_data *data, int i);
int 	parsing_floor_ceiling(t_data *data);
int		ft_isdigit_comma(int c, int *commas);
int		check_colors_and_add_to_struct(t_data *data, char **ceiling_floor_data);
int		check_number_of_array(char **ceiling_floor_data);
int		parsing_map(t_data *data);

/*** raycasting ***/

int		precalculate_rays(t_data *data);

/*** events ***/

void	init_controls(t_data *data);

/*** display ***/

void	put_pixel(int x, int y, int color, t_mlx *mlx);
void	put_line(t_point a, t_point b, int color, t_mlx *mlx);

int		raycasting(t_data *data);
int		get_file(t_data *data, char *av);


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
