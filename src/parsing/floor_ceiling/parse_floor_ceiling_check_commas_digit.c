/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling_check_commas_digit.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:11 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/06 18:09:58 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_if_ceiling_floor_have_comma(char *ceiling_floor_data,
							int i, t_data *data, char **free)
{
	int	len;

	len = ft_strlen(ceiling_floor_data);
	if (!ft_isdigit(ceiling_floor_data[0]) && i == 1)
	{
			free_double_str(free);
			ft_exit_parsing(data, ERROR_CEILING_FLOOR_FIRST_LETTER_WRONG);
	}
	if (len == 1)
	{
		if (!ft_strncmp(&ceiling_floor_data[0], ",", 1) && i == 5)
		{
			free_double_str(free);
			ft_exit_parsing(data, ERROR_CEILING_FLOOR_FIRST_LETTER_WRONG);
		}
	}
	return (FAILURE);
}

static int	check_commas_and_digit(char **ceiling_floor_data, int i,
									int *commas, t_data *data)
{
	int	j;

	j = 0;
	check_if_ceiling_floor_have_comma(ceiling_floor_data[i],
					i, data, ceiling_floor_data);
	while (ceiling_floor_data[i][j])
	{
		if (!ft_isdigit_comma(ceiling_floor_data[i][j], commas))
			{
				free_double_str(ceiling_floor_data);
				ft_exit_parsing(data, ERROR_CEILING_FLOOR_OTHER_THAN_NUMBER);
			}
		if (ceiling_floor_data[i][j] == ',' && ceiling_floor_data[i][j + 1] == ',')
		{
			free_double_str(ceiling_floor_data);
			ft_exit_parsing(data, ERROR_CEILING_FLOOR_TOO_MANY_COMMA);
		}
		j++;
	}
	return (FAILURE);
}

static int	check_strings(char **ceiling_floor_data,
			int number_of_strings, t_data *data)
{
	int	i;
	int	len;
	int	commas;

	i = 1;
	commas = 0;
	while (ceiling_floor_data[i])
	{
		check_commas_and_digit(ceiling_floor_data, i, &commas, data);
		i++;
	}
	len = ft_strlen(ceiling_floor_data[number_of_strings - 1]);
	if (commas != 2
		|| ceiling_floor_data[number_of_strings - 1][len - 1] == ',')
		{
			free_double_str(ceiling_floor_data);
			ft_exit_parsing(data, ERROR_CEILING_FLOOR_ARGUMENTS_PROBLEMS);
		}
	return (FAILURE);
}

void	strdup_raw_cub_file(t_data *data, char c, char *str)
{
	if (c == 'C')
		data->textures->ceiling_color.raw = ft_strdup(str);
	else if (c == 'F')
		data->textures->floor_color.raw = ft_strdup(str);
}

int	check_and_add_color_ceiling_floor(t_data *data, int i)
{
	char	**ceiling_floor_data;
	int		len;

	strdup_raw_cub_file(data, data->map_info->file_cub[i][0],
		data->map_info->file_cub[i]);
	ceiling_floor_data = ft_split_charset(data->map_info->file_cub[i], " \t");
	len = ft_strlen_double_str(ceiling_floor_data);
	if (ft_strlen(ceiling_floor_data[0]) > 1 || len > 6 || len < 2)
	{
		free_double_str(ceiling_floor_data);
		ft_exit_parsing(data, ERROR_CEILING_FLOOR_ARGUMENTS_PROBLEMS);
	}
	check_strings(ceiling_floor_data, len, data);
	check_colors_and_add_to_struct(data, ceiling_floor_data);
	free_double_str(ceiling_floor_data);
	return (FAILURE);
}
