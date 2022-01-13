/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:37:03 by vbachele          #+#    #+#             */
/*   Updated: 2021/09/02 22:11:23 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_3d.h"

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