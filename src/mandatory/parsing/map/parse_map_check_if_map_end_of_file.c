/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check_if_map_end_of_file.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:26 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/23 18:30:06 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// je check si la premiere ligne de la map existe bien

int	first_or_last_line_of_map_exist(char *file_cub)
{
	int	i;

	i = 0;
	while (file_cub[i] == ' '
		|| file_cub[i] == '\t'
		|| file_cub[i] == '1')
		i++;
	if (file_cub[i] == '\0')
		return (FAILURE);
	return (SUCCESS);
}

static	int	walls_and_colors_line_count(char *file_cub, int *count)
{
	if (!ft_strncmp(file_cub, "NO", 2))
		(*count)++;
	else if (!ft_strncmp(file_cub, "EA", 2))
		(*count)++;
	else if (!ft_strncmp(file_cub, "SO", 2))
		(*count)++;
	else if (!ft_strncmp(file_cub, "WE", 2))
		(*count)++;
	else if (!ft_strncmp(file_cub, "C", 1))
		(*count)++;
	else if (!ft_strncmp(file_cub, "F", 1))
		(*count)++;
	return (FAILURE);
}

static	int	check_walls_colors(char *file_cub, int *count)
{
	int	i;
	int	tmp;

	tmp = (*count);
	i = -1;
	walls_and_colors_line_count(file_cub, count);
	if (tmp == (*count) - 1)
		return (FAILURE);
	return (SUCCESS);
}

int	check_empty_line(char *file_cub)
{
	int	i;

	i = 0;
	while (file_cub[i] == ' ' || file_cub[i] == '\t')
		i++;
	if (file_cub[i] == '\0')
		return (FAILURE);
	return (SUCCESS);
}

int	map_if_in_good_place(t_map *map_info, t_data *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (map_info->file_cub[++i])
	{
		if (!check_walls_colors(map_info->file_cub[i], &count))
			continue ;
		else if (!check_empty_line(map_info->file_cub[i]))
			continue ;
		else if (!first_or_last_line_of_map_exist(map_info->file_cub[i])
			&& count == 6)
		{
			map_info->first_line = i;
			return (FAILURE);
		}
		else
			ft_exit_parsing(data, MAP_NOT_AT_END);
	}
	return (FAILURE);
}
