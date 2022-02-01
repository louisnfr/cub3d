/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:28:53 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/01 15:54:17 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_move *init_move(void)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (!move)
		return (NULL);
	ft_memset(move, 0, sizeof(t_move));
	return (move);
}

void	init_mouse(t_mouse *mouse)
{
	mouse->mb_is_pressed = FALSE;
	mouse->lb_is_pressed = FALSE;
	mouse->rb_is_pressed = FALSE;
	mouse->x = 0;
	mouse->y = 0;
	mouse->old_x = 0;
	mouse->old_y = 0;
}
