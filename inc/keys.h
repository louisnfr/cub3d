/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:15:48 by lraffin           #+#    #+#             */
/*   Updated: 2022/03/01 16:20:10 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__
#  define LEFT_MB 1
#  define RIGHT_MB 3
#  define MIDDLE_MB 2
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define Q 113
#  define M 109
#  define F 102
#  define E 101
#  define UP 65362
#  define LEFT 65361
#  define DOWN 65364
#  define RIGHT 65363
#  define SHIFT 65505
#  define ESC 65307
# else
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define Q 12
#  define E 14
#  define UP 126
#  define LEFT 123
#  define DOWN 125
#  define RIGHT 124
#  define ESC 53
# endif

#endif
