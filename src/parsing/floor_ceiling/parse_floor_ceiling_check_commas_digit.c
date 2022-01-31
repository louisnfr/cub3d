/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling_check_commas_digit.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:11 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 14:56:12 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_if_ceiling_floor_have_comma(char *ceiling_floor_data, int i)
{
	int	len;

	len = ft_strlen(ceiling_floor_data);
	if (!ft_isdigit(ceiling_floor_data[0]) && i == 1)
		return (EXIT_FAILURE);
	if (len == 1)
	{
		if (!ft_strncmp(&ceiling_floor_data[0], ",", 1) && i == 5)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_commas_and_digit(char *ceiling_floor_data, int i, int *commas)
{
	int	j;

	j = 0;
	if (check_if_ceiling_floor_have_comma(ceiling_floor_data, i))
		return (EXIT_FAILURE);
	while (ceiling_floor_data[j])
	{
		if (!ft_isdigit_comma(ceiling_floor_data[j], commas))
			return (EXIT_FAILURE);
		if (ceiling_floor_data[j] == ',' && ceiling_floor_data[j + 1] == ',')
			return (EXIT_FAILURE);
		j++;
	}
	return (EXIT_SUCCESS);
}

static int	check_strings(char **ceiling_floor_data, int number_of_strings)
{
	int	i;
	int	len;
	int	commas;

	i = 1;
	commas = 0;
	while (ceiling_floor_data[i])
	{
		if (check_commas_and_digit(ceiling_floor_data[i], i, &commas))
			return (EXIT_FAILURE);
		i++;
	}
	len = ft_strlen(ceiling_floor_data[number_of_strings - 1]);
	if (commas != 2
		|| ceiling_floor_data[number_of_strings - 1][len - 1] == ',')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	strdup_raw_cub_file(t_data *data, char c, char *str)
{
	if (c == 'C')
		data->sprites->ceiling_color.raw = ft_strdup(str);
	else if (c == 'F')
		data->sprites->floor_color.raw = ft_strdup(str);
}

int	check_and_add_color_ceiling_floor(t_data *data, int i)
{
	char	**ceiling_floor_data;
	int		len;

	strdup_raw_cub_file(data, data->map_info->file_cub[i][0],
		data->map_info->file_cub[i]);
	ceiling_floor_data = ft_split_charset(data->map_info->file_cub[i], " \t");
	len = check_number_of_array(ceiling_floor_data);
	if (ft_strlen(ceiling_floor_data[0]) > 1
		|| len > 6 || len < 2
		|| check_strings(ceiling_floor_data, len)
		|| check_colors_and_add_to_struct(data, ceiling_floor_data))
	{
		free_double_str(ceiling_floor_data);
		return (EXIT_FAILURE);
	}
	free_double_str(ceiling_floor_data);
	return (EXIT_SUCCESS);
}
