/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:31:04 by vbachele          #+#    #+#             */
/*   Updated: 2021/09/05 18:34:22 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_3d.h"

int		affichage_game(t_root *root)
{
	root->win_ptr = mlx_new_window(root->mlx_ptr, 1920, 1080, "Dragon Ball Evolution\n");
	if (root->win_ptr == NULL)
	{
		free(root->mlx_ptr);
		return (MLX_ERROR);
	}
	mlx_hook(root->win_ptr, 12, 1L << 15, affichage_and_creation_sprites, root);
	//mlx_hook(data->win_ptr, 2, 1l << 0, &handle_keypress, data);
	mlx_hook(root->win_ptr, 17, 0, free_all_functions, root);
	mlx_loop(root->mlx_ptr);
	//free(root->mlx_ptr);
 return 0;
}