/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor_ceiling_split_color.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:56:16 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 22:16:41 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	add_color_to_struct(char *tmp_split, int i, t_data *data, int color)
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

static	int	check_rgb_errors(char *tmp_split)
{
	int	color;

	color = atoi(tmp_split);
	if (color > 255 || color < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int	check_len_superior_to_four(char **tmp_split)
{
	int	len;

	len = ft_strlen_double_str(tmp_split);
	if (len > 4)
	{
		free_double_str(tmp_split);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_rgb(t_color color, t_data *data, int c)
{
	char	**tmp_split;
	int		i;

	i = 1;
	tmp_split = ft_split_charset(color.raw, " \t," );
	if (check_len_superior_to_four(tmp_split))
		return (EXIT_FAILURE);
	while (tmp_split[i])
	{
		if (check_rgb_errors(tmp_split[i]))
		{
			free_double_str(tmp_split);
			return (EXIT_FAILURE);
		}
		add_color_to_struct(tmp_split[i], i, data, c);
		i++;
	}
	free_double_str(tmp_split);
	return (EXIT_SUCCESS);
}

int	check_colors_and_add_to_struct(t_data *data, char **ceiling_floor_data)
{
	t_color	*c;
	t_color	*f;

	c = &data->sprites->ceiling_color;
	f = &data->sprites->floor_color;
	if (ceiling_floor_data[0][0] == 'C')
	{
		if (check_rgb(data->sprites->ceiling_color, data, 1))
			return (EXIT_FAILURE);
		c->hex_color = ft_rgb_to_color(0, c->r, c->g, c->b);
	}
	else if (ceiling_floor_data[0][0] == 'F')
	{
		if (check_rgb(data->sprites->floor_color, data, 2))
			return (EXIT_FAILURE);
		f->hex_color = ft_rgb_to_color(0, f->r, f->g, f->b);
	}
	return (EXIT_SUCCESS);
}
