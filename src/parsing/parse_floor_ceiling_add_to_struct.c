#include "cub3d.h"

static int check_number_of_array(char **ceiling_floor_data)
{
	int	i;

	i = 0;
	while(ceiling_floor_data[i])
		i++;
	return(i);
}

// static int	check_if_ceiling_floor_have_commas(t_data *data, char **ceiling_floor_data, int i)
// {
// 	int j;
// 	int	commas; // rules : 2 commas apres chaque chiffre et pas de commas a la fin
// 	int len;

// 	len = 0;
// 	commas = 0;
// 	(void) data;
// 	j = 0; // on commence au deuxieme argument
// 	while (++j < i)
// 	{
// 		len = ft_strlen(ceiling_floor_data[j]);
// 		if (len == 1 && ft_strncmp(&ceiling_floor_data[j][0], ",", 1) && i != 1)
// 			commas++;
// 		else if (ft_strncmp(&ceiling_floor_data[j][len], ",", 1))
// 			commas++;
// 	}
// 	return (EXIT_SUCCESS);
// }

int	check_and_add_color_ceiling_floor(t_data *data, int i)
{
	char	**ceiling_floor_data;
	int		len;

	ceiling_floor_data = ft_split_charset(data->map_info->file_cub[i], " \t");
	len = check_number_of_array(ceiling_floor_data);
	if (ft_strlen(ceiling_floor_data[0]) > 1 || len > 6 || len < 2)
	{
		free_double_str(ceiling_floor_data);
		return (EXIT_FAILURE);
	}
	// if (check_if_ceiling_floor_have_commas(data, ceiling_floor_data, len))
	// 	return (EXIT_FAILURE);
	free_double_str(ceiling_floor_data);
	return (EXIT_SUCCESS);
}