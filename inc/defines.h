/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:14:39 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/18 15:02:56 by lraffin          ###   ########.fr       */
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
# define TEXTURES	4
# define MAP_SIZE   0.15

# define DR 0.0174533
# define PI 3.14159265

# define PLAYER "paplay"
# define BACKGROUND " &"
# define OPTIONS " > /dev/null 2>&1"

# define FOV 60

typedef enum e_dir
{
	NO,
	SO,
	EA,
	WE,
	DO,
}	t_dir;

#endif
