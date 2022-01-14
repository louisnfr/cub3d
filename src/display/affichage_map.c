/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:26:56 by vbachele          #+#    #+#             */
/*   Updated: 2021/09/04 21:52:36:34 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define	RED_PIXEL 0xFF0000

int	affichage_and_creation_sprites(t_root *root)
{
	creation_sprites(root);
	affichage_sprites_screen(root);
	return (0);
}

void	affichage_sprites_screen(t_root *root)
{
	root->x = 0;
	while (root->map[root->x])
	{
		root->y = 0;
		while (root->map[root->x][root->y])
		{
			affichage_sprites_screen2(root);
			root->y++;
		}
		root->x++;
	}
}

void	affichage_sprites_screen2(t_root *root)
{
	int i;
	i = 0;
	if (root->map[root->x][root->y] == '1')
		mlx_put_image_to_window(root->mlx_ptr,
		root->win_ptr,root->sprites->wall, 64 *root->y, 64 *root->x);
	// else if (root->map[root->x][root->y] == '0')
	// 	// mlx_put_image_to_window(root->mlx_ptr,
	// 	// root->win_ptr,root->sprites->floor, 64 *root->y, 64 *root->x);
	else if (root->map[root->x][root->y] == 'P')
	{
		while(i < 10)
		{
			mlx_pixel_put(root->mlx_ptr, root->win_ptr, 64 *root->y, 64 *root->x, RED_PIXEL);
			i++;
		}
	}
}
