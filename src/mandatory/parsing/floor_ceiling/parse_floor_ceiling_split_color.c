/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling_split_color.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:16 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/24 16:06:32 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	add_color_to_struct(char *tmp_split, int i,
						t_data *data, int color)
{
	int	rgb;

	rgb = ft_atoi(tmp_split);
	if (i == 1 && color == 1)
		data->textures->ceiling_color.r = rgb;
	else if (i == 1 && color == 2)
		data->textures->floor_color.r = rgb;
	else if (i == 2 && color == 1)
		data->textures->ceiling_color.g = rgb;
	else if (i == 2 && color == 2)
		data->textures->floor_color.g = rgb;
	else if (i == 3 && color == 1)
		data->textures->ceiling_color.b = rgb;
	else if (i == 3 && color == 2)
		data->textures->floor_color.b = rgb;
}

static	int	check_rgb_errors(char *tmp_split, t_data *data,
			char **free, char **free_2)
{
	int	color;

	color = ft_atoi(tmp_split);
	if (color > 255 || color < 0)
	{
		free_double_str(free);
		free_double_str(free_2);
		ft_exit_parsing(data, CEILING_FLOOR_LEN_COLOR_TOO_LONG);
	}
	return (FAILURE);
}

static int	check_rgb(t_color color, t_data *data, int c, char **free)
{
	char	**tmp_split;
	int		i;

	i = 1;
	tmp_split = ft_split_charset(color.raw, " \t,");
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

	c = &data->textures->ceiling_color;
	f = &data->textures->floor_color;
	if (ceiling_floor_data[0][0] == 'C')
	{
		check_rgb(data->textures->ceiling_color, data, 1, ceiling_floor_data);
		c->hex_color = ft_rgb_to_color(0, c->r, c->g, c->b);
	}
	else if (ceiling_floor_data[0][0] == 'F')
	{
		check_rgb(data->textures->floor_color, data, 2, ceiling_floor_data);
		f->hex_color = ft_rgb_to_color(0, f->r, f->g, f->b);
	}
	return (FAILURE);
}
