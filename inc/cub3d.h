/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:09:01 by lraffin           #+#    #+#             */
/*   Updated: 2022/03/06 15:09:03 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs.h"

/*** init ***/

t_data		*init_data(void);
t_mlx		*init_mlx(t_data *data);
t_move		*init_move(t_data *data);
t_player	*init_player(t_data *data);
void		init_struct(t_data *data);
void		init_mouse(t_mouse *mouse);
void		set_player_dir(t_player *player, t_data *data);

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
int		check_and_add_path_walls(t_data *data, int i, char *face_wall);

/*** parsing_map ***/

int		parsing_map(t_data *data);
int		map_if_in_good_place(t_map *map_info, t_data *data);
int		store_data_map(t_map *map_info, t_data *data);
int		first_or_last_line_of_map_exist(char *file_cub);
int		check_empty_line(char *file_cub);
int		check_error_1st_letter_last_letter(char **map, t_data *data);
int		check_if_letters_are_good(t_data *data);
int		check_map_is_valid(t_data *data);

/*** parsing_floor_ceiling ***/

int		check_if_floor_ceiling_exist(t_data *data);
int		check_and_add_color_ceiling_floor(t_data *data, int i);
int		parsing_floor_ceiling(t_data *data);
int		check_colors_and_add_to_struct(t_data *data, char **ceiling_floor_data);

/*** raycasting ***/

int		raycasting(t_player *player, t_data *data);
void	draw_texture(t_ray *ray, t_tex *t, int x, t_data *data);

/*** events ***/

void	init_controls(t_data *data);
void	move_player(t_data *data);
void	update_pos(t_data *data);
void	orient_player(t_camera *cam, t_vector *vect, t_data *data);

/*** display ***/

void	put_pixel(int x, int y, int color, t_mlx *mlx);
void	put_vline(int x, t_point b, int color, t_mlx *mlx);
void	cub_load_textures(t_mlx *mlx, t_textures *wall, t_data *data);
void	cub_load_xpm(t_mlx *mlx, int *tex, char *path);

/*** exit ***/

int		free_data(t_data *data);
int		ft_exit_parsing(t_data *data, char *error_message);
void	ft_error_message(char *str);
int		exit_all(t_data *data);
void	free_double_int(int *tab);

/////////////////////////////     BONUS    ////////////////////////////////////

/*** utils ***/

void	init_bonus_struct(t_data *data);
int		store_data_bonus(t_map *map, t_data *data);
int		ft_strlen_double_str_find_element(char **double_str, char c);
int		play_sound(char *path, int volume);

/*** mini_map ***/

int		mini_map(t_data *data);

/*** doors ***/

int		doors(t_data *data);
int		close_doors(t_map *map, t_vector *v, t_doors *doors);

/*** floor_ceiling ***/

int		floor_ceiling_bonus(t_data *data);
int		floor_casting_bonus(t_data *data, t_player *player);

/*** sprites ***/
int		zbuffer_sprites(t_data *data, int x, t_ray *ray);
int		sprite_casting(t_data *data, t_sprites *spr, t_vector *player,
					t_player *play);
void	lowest_highest_height_pixel(t_sprites *spr);
void	lowest_highest_width_pixel(t_sprites *spr);
void	store_color_in_buffer(t_sprites *spr, t_data *data, int i);
int		sprites_move(t_data *data, int a, t_vector *vect);

/*** draw_bonus ***/
int			draw_floor_ceiling_bonus(t_ray_b *ray_b, t_data *data);
int			draw_sprites_bonus(t_sprites *spr, t_data *data);
void		ennemy_is_rolling_ball(t_sprites *spr, t_data *data, int i);
void		ennemy_is_stormtrooper(t_sprites *spr, t_data *data, int i);
void		ennemy_is_darth_vador(t_sprites *spr, t_data *data, int i);
void		define_texy(t_sprites *spr, int y);
void		define_texx(t_sprites *spr, int stripe);
void		store_buffer_and_print(t_data *data, int stripe,
										u_int32_t color, int y);
void		draw_weapons(t_data *data);
void		ennemy_is_hit(t_sprites *spr, t_data *data, int i);

/*** draw sprites ***/
void		draw_r2d2_xwing_lightsaber_yoda(t_data *data, int stripe,
			int color, int y, int i);
void		draw_rolling_ball(t_data *data, int stripe,
			int color, int y, int i);
void		draw_darth_vader(t_data *data, int stripe,
			int color, int y, int i);
void		draw_stormtrooper(t_data *data, int stripe,
			int color, int y, int i);
int			draw_sprites_bonus(t_sprites *spr, t_data *data);
void		draw_attack_lightsaber(t_data *data);
void 		light_saber_is_taken(t_data *data, int stripe, int y, int i);
void		xwing_end(t_sprites *spr, t_data *data, int i);

/*** parsing bonus ***/

int		parse_file_sprites(t_data *data, char *av);
char	**put_sprite_in_struct(t_data *data, char *arg_sprite);
int		cub_load_sprites(t_data *data, t_mlx *mlx, t_sprite_f *sf);

/*** free bonus ***/

void	free_bonus_textures(t_data *data, t_textures *textures);
void	free_sprites(t_data *data);

#endif
