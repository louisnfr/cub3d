/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:05:22 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/14 17:25:31 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calcul_tableau_map(t_root *root, char **argv)
{
	char			*line;
	int				fd;
	int				flag;
	t_list			*new;
	t_list			*tmp;

	fd = open(argv[1], O_RDONLY);
	flag = 1;
	while (flag)
	{
		flag = get_next_line(fd, &line);
		new = ft_lstnew(line);
		if (!new)
			return (0);
		ft_lstadd_back(&root->lst, new);
		root->height++;
	}
	tmp = root->lst;
	root->width = ft_strlen(tmp->line);
	calcul_tableau_2_dimensions(root, tmp);
	return (0);
}

void	calcul_tableau_2_dimensions(t_root *root, t_list *tmp)
{
	int	i;

	root->map = (char **)ft_calloc(root->height + 1, sizeof(char *));
	root->x = 0;
	while (tmp != NULL)
	{
		i = 0;
		root->y = 0;
		root->map[root->x] = (char *)malloc(sizeof(char) * (root->width + 1));
		while (tmp->line[i])
		{
			root->map[root->x][root->y] = tmp->line[i];
			i++;
			root->y++;
		}
		root->map[root->x][root->y] = 0;
		root->x++;
		tmp = tmp->next;
	}
	root->map[root->x] = 0;
	//Calcul_Width_Height(data);
	//Calcul_Nombre_Collectible(data);
}
