/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:14:39 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/27 15:49:55 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_W 1024
# define HALF_WIN_W WIN_W / 2
# define WIN_H 512
# define HALF_WIN_H WIN_H / 2

# define FOV 60
# define HALF_FOV FOV / 2

# define INCREM_ANGLE FOV / WIN_W
# define PLAYER_ANGLE 0

# define PRECISION 64

# define DR 0.0174533
# define PI 3.1415926535
# define P2 1.5707963268
# define P3 1.0471975512

typedef enum s_boolean
{
	FAILURE = 0,
	SUCCESS = 1,
	FALSE = 0,
	TRUE = 1,
}	t_boolean;


#endif
