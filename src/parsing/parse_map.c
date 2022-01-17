/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:05:22 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/17 16:28:48 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map(t_data *data, char **argv)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("-%s-\n", line);
		if (ft_strlen(line) > data->map_info->width)
			data->map_info->width = ft_strlen(line);
		data->map_info->height++;
		free(line);
	}
	close(fd);
	// init_map_tab(data);
	return (EXIT_SUCCESS);
}

// void	calcul_tableau_2_dimensions(t_data *data, t_map *tmp)
// {
// 	int	i;

// 	data->map_info->map = ft_calloc(data->map_info->height + 2, sizeof(char *));
// 	data->x = 0;
// 	while (tmp != NULL)
// 	{
// 		i = 0;
// 		data->y = 0;
// 		data->map_info->map[data->x] = malloc(sizeof(char) * (data->map_info->width + 1));
// 		while (tmp->line[i])
// 		{
// 			data->map_info->map[data->x][data->y] = tmp->line[i];
// 			i++;
// 			data->y++;
// 		}
// 		data->map_info->map[data->x][data->y] = 0;
// 		data->x++;
// 		tmp = tmp->next;
// 	}
// 	data->map_info->map[data->x] = 0;
// 	Calcul_Width_Height(data);
// 	Calcul_Nombre_Collectible(data);
// }
