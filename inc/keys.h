/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:15:48 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/24 20:38:18 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__
#  define LEFT 65361
#  define UP 65362
#  define RIGHT 65363
#  define DOWN 65364
#  define ESC 65307
# else
#  define UP 126
#  define DOWN 125
#  define RIGHT 124
#  define LEFT 123
#  define ESC 53
# endif

#endif
