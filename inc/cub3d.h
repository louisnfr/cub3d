/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:12:00 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 19:12:04 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs.h"

/*** init ***/

t_data	*init_data(void);
void	init_struct(t_data *data);
void	init_mouse(t_mouse *mouse);

/*** parsing_general ***/

char	**ft_split_charset(char *str, char *charset);
void	check_input(int ac, char **av);
int		parse_file(t_data *data);
int		get_file(t_data *data, char *av);
void	check_input(int ac, char **av);

/*** parsing_walls ***/

int		check_all_directions(t_data *data);
int		parsing_walls(t_data *data);
int		add_img_wall_to_mlx(t_data *data);
void	error_message_walls(void);
int		check_and_add_path_walls(t_data *data, int i, char *face_wall);

/*** parsing_map ***/

int		parsing_map(t_data *data);
int		map_if_in_good_place(t_map *map_info);
int		store_data_map(t_map *map_info);
int		first_or_last_line_of_map_exist(char *file_cub);
int		check_empty_line(char *file_cub);
int		check_error_1st_letter_last_letter(char **map);
int		check_if_letters_are_good(t_data *data);
int		check_map_is_valid(t_data *data);

/*** parsing_floor_ceiling ***/

int		check_if_floor_ceiling_exist(t_data *data);
int		check_and_add_color_ceiling_floor(t_data *data, int i);
int		parsing_floor_ceiling(t_data *data);
int		check_colors_and_add_to_struct(t_data *data, char **ceiling_floor_data);

/*** parsing_utils ***/

int		ft_isdigit_comma(int c, int *commas);
char	**ft_split_charset(char *str, char *charset);
int		check_number_of_array(char **ceiling_floor_data);
int		create_trgb(int t, int r, int g, int b);

/*** raycasting ***/

int		raycasting(t_player *player, t_data *data);

/*** events ***/

void	init_controls(t_data *data);
void	move_player(int key, t_player *player, t_data *data);
void	orient_player(int key, t_camera *cam, t_vector *vect);

/*** display ***/

void	put_pixel(int x, int y, int color, t_mlx *mlx);
void	put_vline(int x, t_point b, int color, t_mlx *mlx);

/*** exit ***/

int		free_data(t_data *data);

#endif
