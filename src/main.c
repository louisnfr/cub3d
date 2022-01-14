/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:58:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/14 18:10:42 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	initialisation_malloc_structure(t_root *root)
{
	if (!root)
		return (0);
	root->sprites = malloc(sizeof(t_sprites));
	if (!root->sprites)
		return (0);
	return (0);
}

int main(int ac, char** av)
{
	t_root	*root;

	// (void)ac;
	// (void)av;
	// root = malloc(sizeof(t_root));
	// root->mlx_ptr = mlx_init();
	// root->win_ptr = mlx_new_window(root->mlx_ptr, 1920, 1080, "Dragon Ball Evolution\n");
	// if (root->win_ptr == NULL)
	// {
	// 	free(root->mlx_ptr);
	// 	return (MLX_ERROR);
	// }
	// mlx_loop(root->mlx_ptr);
	// printf("check\n");
	if (ac == 2)
	{
		root = malloc(sizeof(t_root));
		initialisation_malloc_structure(root);
		initialisation_structure(root);
		//if (check_If_Ber(av))
			//return (0);
		root->mlx_ptr = mlx_init();
		if (root->mlx_ptr == NULL)
			return (MLX_ERROR);
		calcul_tableau_map(root, av);
		//if (check_Errors(root, &root->lst) == 1)
			//return (0);;
		affichage_game(root);
	}
	else
		printf("Erreur, mauvais nombre d'arguments\n");
}
