/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:49:32 by vbachele          #+#    #+#             */
/*   Updated: 2021/09/04 21:49:41 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_3d.h"

int	free_all_functions(t_root *root)
{
	if (root->sprites)
		free(root->sprites);
	if (root->lst)
		ft_lstclear(&root->lst, del_content);
	free_double_tableau(root);
	mlx_destroy_window(root->mlx_ptr, root->win_ptr);
	if (root)
		free(root);
	free(root->mlx_ptr);
	exit(1);
}

void	del_content(t_list **lst)
{
	free((*lst)->line);
	(*lst)->line = NULL;
}

void	free_double_tableau(t_root *root)
{
	int	i;

	i = 0;
	while (root->map[i])
	{
		free(root->map[i]);
		i++;
	}
	free(root->map);
}