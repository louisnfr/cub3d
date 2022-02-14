/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:14:39 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/14 14:34:20 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_W 1280
# define WIN_H 800
# define MINIMAP_W 320
# define MINIMAP_H 200
# define TEX_W 		64
# define TEX_H 		64
# define TEXTURES	4
# define MAP_SIZE   0.15
# define NUM_SPRITE	4

# define DR 0.0174533
# define PI 3.14159265

# define FOV 60

typedef enum e_dir
{
	NO,
	SO,
	EA,
	WE,
}	t_dir;

#endif
