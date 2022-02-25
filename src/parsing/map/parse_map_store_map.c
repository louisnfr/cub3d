/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_store_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:34 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/23 18:30:27 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_max_width(t_map *map_info)
{
	int		start_tab;
	int		end_tab;
	char	**map;

	start_tab = map_info->first_line;
	end_tab = map_info->last_line;
	map = map_info->file_cub;
	while (start_tab <= end_tab)
	{
		if (ft_strlen(map[start_tab]) > map_info->map_width_line)
			map_info->map_width_line = ft_strlen(map[start_tab]);
		start_tab++;
	}
}

static char	**allocate_map(t_map *map_info)
{
	char	**map;
	int		size;
	int		i;

	size = (map_info->last_line + 1) - map_info->first_line;
	map = ft_calloc(size + 1, sizeof(char *));
	if (!map)
		return (NULL);
	get_max_width(map_info);
	i = -1;
	while (++i < size)
	{
		map[i] = ft_calloc((map_info->map_width_line + 1), sizeof(char));
		if (!map[i])
			return (NULL);
	}
	map[i] = 0;
	return (map);
}

static int	fill_map(t_map *map_info, t_data *data)
{
	int		i;
	int		j;
	int		start_tab;
	int		end_tab;
	char	**map;

	start_tab = map_info->first_line;
	end_tab = map_info->last_line;
	j = 0;
	map = allocate_map(map_info);
	if (!map)
		ft_exit_parsing(data, MAP_MALLOC_PROBLEM);
	while (start_tab <= end_tab)
	{
		i = 0;
		while (i < ft_strlen(map_info->file_cub[start_tab]))
		{
			map[j][i] = map_info->file_cub[start_tab][i];
			i++;
		}
		j++;
		start_tab++;
	}
	map_info->map = map;
	return (FAILURE);
}

static	int	check_and_store_last_line(t_map *map_info, t_data *data)
{
	int	tmp;

	tmp = ft_strlen_double_str(map_info->file_cub);
	while (--tmp >= 0)
	{
		if (!check_empty_line(map_info->file_cub[tmp]))
			continue ;
		else if (!first_or_last_line_of_map_exist(map_info->file_cub[tmp]))
		{
			map_info->last_line = tmp;
			break ;
		}
		else
			ft_exit_parsing(data, MAP_NOT_AT_END);
	}
	return (FAILURE);
}

int	store_data_map(t_map *map_info, t_data *data)
{
	check_and_store_last_line(map_info, data);
	if ((map_info->last_line + 1) - map_info->first_line < 3)
		ft_exit_parsing(data, MAP_TOO_FEW_LINES);
	fill_map(map_info, data);
	return (FAILURE);
}
