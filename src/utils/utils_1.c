/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:37:03 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/14 17:26:00 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialisation_structure(t_root *root)
{
	root->i = 0;
	root->x = 0;
	root->y = 0;
	root->player_x = 0;
	root->player_y = 0;
	root->width = 0;
	root->height = 0;
	root->Ennemy_1_x = 0;
	root->Ennemy_1_y = 0;
}
