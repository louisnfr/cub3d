/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:58:32 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/13 19:02:11 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube_3d.h"

int	initialisation_malloc_structure(t_root *root)
{
	if (!root)
		return (0);
	root->sprites = malloc(sizeof(t_sprites));
	if (!root->sprites)
		return (0);
	return (0);
}

int main(int argc, char** argv)
{ 
	t_root	*root;

	if (argc == 2)
	{
		root = malloc(sizeof(t_root));
		initialisation_malloc_structure(root);
		initialisation_structure(root);
		//if (check_If_Ber(argv))
			//return (0);
		root->mlx_ptr = mlx_init();
		if (root->mlx_ptr == NULL)
			return (MLX_ERROR);
		calcul_tableau_map(root, argv);
		//if (check_Errors(root, &root->lst) == 1)
			//return (0);;
		affichage_game(root);
	}
	else
		printf("Erreur, mauvais nombre d'arguments\n");
}
