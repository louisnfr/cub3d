/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:12:00 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/18 15:53:12 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define	CUBE_3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "colors.h"
# include "libft.h"
# include "../mlx/mlx.h"

# define MLX_ERROR 1
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define K 40
# define T 17
# define XK_RIGHT 124
# define XK_LEFT 123
# define XK_DOWN 125
# define XK_UP 126

# define HEIGHT 1080
# define WIDTH 1920

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

typedef enum s_boolean
{
	FAILURE = 0,
	SUCCESS = 1,
	FALSE = 0,
	TRUE = 1,
}	t_boolean;

/*** init ***/

t_data	*init_data(void);
void	init_mouse(t_mouse *mouse);

/*** events ***/

void	init_controls(t_data *data);

/*** display ***/

void	draw_line(t_point a, t_point b, t_data *data);

int		draw_map(t_data *data);
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
