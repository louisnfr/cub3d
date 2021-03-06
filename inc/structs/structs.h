/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:09:42 by lraffin           #+#    #+#             */
/*   Updated: 2022/03/06 15:09:42 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "parsing.h"
# include "player.h"
# include "bonus/player_bonus.h"
# include "bonus/parsing_bonus.h"
# include "bonus/sprites.h"

// struct for our mlx

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*buf1;
	int		bpp;
	int		length;
	int		endian;
	int		x;
	int		y;
	int		*add;
}	t_mlx;

// initial structure

typedef struct s_data
{
	struct s_player			*player;
	struct s_move			*move;
	t_mlx					*mlx;
	struct s_mouse			*mouse;
	struct s_map			*map_info;
	struct s_sprites		*sprites;
	struct s_textures		*textures;
	struct s_minimap		minimap; //bonus
	struct s_doors			doors; // bonus
	struct s_ray			ray;
	struct s_ray_b			ray_b; // bonus
	struct s_sprite_f		sprite_f[200]; // bonus
}	t_data;

#endif
