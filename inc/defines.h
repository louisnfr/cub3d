/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:14:39 by lraffin           #+#    #+#             */
/*   Updated: 2022/03/01 15:28:09 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_W 1280
# define WIN_H 800
# define MINIMAP_W 320
# define MINIMAP_H 200
# define TEX_W 		256
# define TEX_H 		256
# define WEAPON_W	512
# define WEAPON_H	170
# define SPRITE_W	256 // for the sprites please respect these pixels
# define SPRITE_H	256 // for the sprites please respect these pixels
# define TEXTURES	4
# define MAP_SIZE   0.15
# define NUM_SPRITE	50 // DOIT ETRE EXACT AU NOMBRE

# define DR 0.0174533
# define PI 3.14159265

# define FOV 60

# define PLAYER "paplay"
# define BACKGROUND " &"
# define OPTIONS " > /dev/null 2>&1"

typedef enum e_dir
{
	NO,
	SO,
	EA,
	WE,
	DO,
}	t_dir;

#endif
