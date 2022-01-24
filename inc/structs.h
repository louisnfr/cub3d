/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:12:07 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/24 12:12:43 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char			**map;
	// char			*line;
	int				width;
	int				height;
	// struct s_map	*next;

}	t_map;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;

} t_sprites;

typedef struct s_mouse
{
	char	mb_is_pressed;
	char	lb_is_pressed;
	char	rb_is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*addr;
	int			player_x;
	int			player_y;
	int			i;
	int			j;
	int			x;
	int			y;
	t_mouse		*mouse;
	t_map		*map_info;
	t_sprites	*sprites;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif
