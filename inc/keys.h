/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:15:48 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/27 23:04:28 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__
#  define W 65362
#  define A 65361
#  define S 65364
#  define D 65363
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
