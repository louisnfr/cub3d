/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:14:39 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/31 18:31:27 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_W 1280
# define WIN_H 800

# define DR 0.0174533
# define PI 3.14159265

# define FOV 60

typedef enum s_boolean
{
	FAILURE = 0,
	SUCCESS = 1,
	FALSE = 0,
	TRUE = 1,
}	t_boolean;

#endif
