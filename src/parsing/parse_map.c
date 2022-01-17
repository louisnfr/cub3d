/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:05:22 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 15:53:29 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map(t_data *data, char **argv)
{
	// char	*line;
	int		fd;
	int		flag;
	t_map	*new;
	t_map	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	flag = 1;
	while (flag > 0)
	{
		flag = get_next_line(fd, &data->map_lst->line);
		printf("-%s-\n", data->map_lst->line);
		new = ft_lstnew(data->map_lst->line);
		if (!new)
			return (EXIT_FAILURE);
		ft_lstadd_back(&data->map_lst, new);
		data->map_lst->height++;
	}
	tmp = data->map_lst;
	data->map_lst->width = ft_strlen(tmp->line);
	calcul_tableau_2_dimensions(data, tmp);
	return (EXIT_SUCCESS);
}

void	calcul_tableau_2_dimensions(t_data *data, t_map *tmp)
{
	int	i;

	data->map_lst->map = ft_calloc(data->map_lst->height + 2, sizeof(char *));
	data->x = 0;
	while (tmp != NULL)
	{
		i = 0;
		data->y = 0;
		data->map_lst->map[data->x] = malloc(sizeof(char) * (data->map_lst->width + 1));
		while (tmp->line[i])
		{
			data->map_lst->map[data->x][data->y] = tmp->line[i];
			i++;
			data->y++;
		}
		data->map_lst->map[data->x][data->y] = 0;
		data->x++;
		tmp = tmp->next;
	}
	data->map_lst->map[data->x] = 0;
	//Calcul_Width_Height(data);
	//Calcul_Nombre_Collectible(data);
}
