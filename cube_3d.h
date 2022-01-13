/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:12:00 by vbachele          #+#    #+#             */
/*   Updated: 2021/09/04 21:50:56 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define	CUBE_3D_H

# include "cube_3d.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MLX_ERROR 1
# define A 0
# define W 13
# define D 2
# define S 1
# define ESC 53
# define K 40
# define T 17
# define XK_RIGHT 124
# define XK_LEFT 123
# define XK_DOWN 125
# define XK_UP 126

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	
} t_sprites;

typedef struct s_root
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			Ennemy_1_x;
	int			Ennemy_1_y;
	int			i;
	int			j;
	int			x;
	int			y;
	char		**map;
	t_list		*lst;
	t_sprites	*sprites;
} t_root; 

int		main(int argc, char ** argv);
int		affichage_game(t_root *root);
int		initialisation_malloc_structure(t_root *root);
void	initialisation_structure(t_root *root);
int		free_All_Fonctions(t_root *root);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(t_list **));
void	ft_lstdelone(t_list *lst, void (*del)(t_list **));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(char *content);
t_list	*ft_lstnew(char *content);
void	*ft_memset(void *ptr, int value, size_t num);
size_t	ft_strlen(const char *str);
int		calcul_tableau_map(t_root *root, char **argv);
void	calcul_tableau_2_dimensions(t_root *root, t_list *tmp);
int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t count, size_t size);
void	del_content(t_list **lst);
void	free_double_tableau(t_root *root);
void	affichage_sprites_screen2(t_root *root);
void	affichage_sprites_screen(t_root *root);
void	creation_sprites(t_root *root);
int		affichage_and_creation_sprites(t_root *root);
int		free_all_functions(t_root *root);

#endif
