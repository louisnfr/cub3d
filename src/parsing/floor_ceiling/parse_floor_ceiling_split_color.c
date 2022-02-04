/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling_split_color.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:16 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/04 12:09:21 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	add_color_to_struct(char *tmp_split, int i,
						t_data *data, int color)
{
	int	rgb;

	rgb = atoi(tmp_split);
	if (i == 1 && color == 1)
		data->sprites->ceiling_color.r = rgb;
	else if (i == 1 && color == 2)
		data->sprites->floor_color.r = rgb;
	else if (i == 2 && color == 1)
		data->sprites->ceiling_color.g = rgb;
	else if (i == 2 && color == 2)
		data->sprites->floor_color.g = rgb;
	else if (i == 3 && color == 1)
		data->sprites->ceiling_color.b = rgb;
	else if (i == 3 && color == 2)
		data->sprites->floor_color.b = rgb;
}

static	int	check_rgb_errors(char *tmp_split, t_data *data, char **free, char **free_2)
{
	int	color;

	color = atoi(tmp_split);
	if (color > 255 || color < 0)
	{
		free_double_str(free);
		free_double_str(free_2);
		ft_exit_parsing(data, ERROR_CEILING_FLOOR_LEN_COLOR_TOO_LONG);
	}
	return (FAILURE);
}

// static	int	check_len_superior_to_four(char **tmp_split, t_data *data)
// {
// 	int	len;

// 	len = ft_strlen_double_str(tmp_split);
// 	if (len > 4)
// 	{
// 		free_double_str(tmp_split);
// 		ft_exit_parsing(data, ERROR_CEILING_FLOOR_LEN_COLOR_TOO_LONG);
// 	}
// 	return (FAILURE);
// }

static int	check_rgb(t_color color, t_data *data, int c, char **free)
{
	char	**tmp_split;
	int		i;

	i = 1;
	tmp_split = ft_split_charset(color.raw, " \t,");
	// check_len_superior_to_four(tmp_split, data);
	while (tmp_split[i])
	{
		check_rgb_errors(tmp_split[i], data, tmp_split, free);
		add_color_to_struct(tmp_split[i], i, data, c);
		i++;
	}
	free_double_str(tmp_split);
	return (FAILURE);
}

int	check_colors_and_add_to_struct(t_data *data, char **ceiling_floor_data)
{
	t_color	*c;
	t_color	*f;

	c = &data->sprites->ceiling_color;
	f = &data->sprites->floor_color;
	if (ceiling_floor_data[0][0] == 'C')
	{
		check_rgb(data->sprites->ceiling_color, data, 1, ceiling_floor_data);
		c->hex_color = ft_rgb_to_color(0, c->r, c->g, c->b);
	}
	else if (ceiling_floor_data[0][0] == 'F')
	{
		check_rgb(data->sprites->floor_color, data, 2, ceiling_floor_data);
		f->hex_color = ft_rgb_to_color(0, f->r, f->g, f->b);
	}
	return (FAILURE);
}
