/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map(delete).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:05:22 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 15:31:18 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static char	**allocate_map(t_map *map)
// {
// 	char	**tab;
// 	int		i;

// 	tab = ft_calloc(map->h + 1, sizeof(char *));
// 	if (!tab)
// 		return (NULL);
// 	i = -1;
// 	while (++i < map->h)
// 	{
// 		tab[i] = ft_calloc(map->w + 1, sizeof(char));
// 		if (!tab[i])
// 			return (NULL);
// 	}
// 	tab[i] = 0;
// 	return (tab);
// }

// static int	fill_map(t_data *data, char *av)
// {
// 	char	*line;
// 	int		ret;
// 	int		fd;
// 	int		i;
// 	int		j;

// 	fd = open(av, O_RDONLY);
// 	data->map->tab = allocate_map(data->map);
// 	if (!data->map->tab || fd < 0)
// 		return (FAILURE);
// 	ret = 1;
// 	j = 0;
// 	while (ret)
// 	{
// 		i = -1;
// 		ret = get_next_line(fd, &line);
// 		if (ret < 0)
// 			return (FAILURE);
// 		while (++i < ft_strlen(line))
// 			data->map->tab[j][i] = line[i];
// 		j++;
// 		free(line);
// 	}
// 	close(fd);
// 	return (SUCCESS);
// }

// int	get_map(t_data *data, char *av)
// {
// 	char	*line;
// 	int		fd;
// 	int		ret;

// 	fd = open(av, O_RDONLY);
// 	if (fd < 0)
// 		return (FAILURE);
// 	ret = 1;
// 	while (ret)
// 	{
// 		ret = get_next_line(fd, &line);
// 		if (ret < 0)
// 			return (FAILURE);
// 		if (ft_strlen(line) > data->map->w)
// 			data->map->w = ft_strlen(line);
// 		data->map->h++;
// 		free(line);
// 	}
// 	close(fd);
// 	return (fill_map(data, av));
// }
