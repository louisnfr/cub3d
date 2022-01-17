/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:12:00 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 16:30:26 by lraffin          ###   ########.fr       */
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

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			player_x;
	int			player_y;
	int			Ennemy_1_x;
	int			Ennemy_1_y;
	int			i;
	int			j;
	int			x;
	int			y;
	t_map		*map_info;
	t_sprites	*sprites;
} t_data;

/*** init ***/

t_data	*init_data(void);

int		affichage_game(t_data *data);
int		get_map(t_data *data, char **argv);
void	calcul_tableau_2_dimensions(t_data *data, t_map *tmp);

void	del_content(t_map **map_info);
void	free_double_tableau(t_data *data);
void	affichage_sprites_screen2(t_data *data);
void	affichage_sprites_screen(t_data *data);
void	create_sprites(t_data *data);
int		affichage_and_creation_sprites(t_data *data);
int		free_all_functions(t_data *data);

/*** utils ***/

void	ft_lstadd_back(t_map **alst, t_map *new);
void	ft_lstclear(t_map **map_info, void (*del)(t_map **));
void	ft_lstdelone(t_map *map_info, void (*del)(t_map **));
t_map	*ft_lstlast(t_map *map_info);
t_map	*ft_lstnew(char *content);
t_map	*ft_lstnew(char *content);

#endif
