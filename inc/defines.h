/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:14:39 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/04 16:55:11 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_W 1280
# define WIN_H 800

# define TEX_W 64
# define TEX_H 64

# define DR 0.0174533
# define PI 3.14159265

# define FOV 60

typedef enum e_dir
{
	NO,
	SO,
	EA,
	WE
}	t_dir;

#endif
