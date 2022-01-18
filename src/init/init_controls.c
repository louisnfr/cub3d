/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:28:53 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/18 17:17:24 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mouse(t_mouse *mouse)
{
	mouse->mb_is_pressed = FALSE;
	mouse->lb_is_pressed = FALSE;
	mouse->rb_is_pressed = FALSE;
	mouse->x = 0;
	mouse->y = 0;
	mouse->previous_x = 0;
	mouse->previous_y = 0;
}
