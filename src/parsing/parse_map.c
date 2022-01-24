/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:05:22 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/24 15:06:39 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**allocate_map(t_map *map_info)
{
	char	**map;
	int		i;

	map = ft_calloc(map_info->height + 1, sizeof(char *));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < map_info->height)
	{
		map[i] = ft_calloc(map_info->width + 1, sizeof(char));
		if (!map[i])
			return (NULL);
	}
	map[i] = 0;
	return (map);
}

static int	fill_map(t_data *data, char *av)
{
	char	*line;
	int		ret;
	int		fd;
	int		i;
	int		j;

	fd = open(av, O_RDONLY);
	data->map_info->map = allocate_map(data->map_info);
	if (!data->map_info->map || fd < 0)
		return (FAILURE);
	ret = 1;
	j = 0;
	while (ret)
	{
		i = -1;
		ret = get_next_line(fd, &line);
		if (ret < 0)
			return (FAILURE);
		while (++i < ft_strlen(line))
			data->map_info->map[j][i] = line[i];
		j++;
		free(line);
	}
	close(fd);
	return (SUCCESS);
}

int	get_map(t_data *data, char *av)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	ret = 1;
	while (ret)
	{
		
		ret = get_next_line(fd, &line);
		// printf("-%s- (%d)\n", line, ret);
		if (ret < 0)
			return (FAILURE);
		if (ft_strlen(line) > data->map_info->width)
			data->map_info->width = ft_strlen(line);
		data->map_info->height++;
		free(line);
	}
	close(fd);
	return (fill_map(data, av));
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
