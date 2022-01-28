#include "cub3d.h"

static	void	add_color_to_struct(char *tmp_split, int i, t_color color)
{
	int	rgb;

	rgb = atoi(tmp_split);
	if (i == 1)
		color.r = rgb;
	else if (i == 2)
		color.g = rgb;
	else if (i == 3)
		color.b = rgb;
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

	len = check_number_of_array(tmp_split);
	if (len > 4)
	{
		free_double_str(tmp_split);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_rgb(t_color color)
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
		add_color_to_struct(tmp_split[i], i, color);
		i++;
	}
	free_double_str(tmp_split);
	return (EXIT_SUCCESS);
}

int	check_colors_and_add_to_struct(t_data *data, char **ceiling_floor_data)
{
	if (ceiling_floor_data[0][0] == 'C')
	{
		if (check_rgb(data->sprites->ceiling_color))
			return (EXIT_FAILURE);
	}
	else if (ceiling_floor_data[0][0] == 'F')
	{
		if (check_rgb(data->sprites->floor_color))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
