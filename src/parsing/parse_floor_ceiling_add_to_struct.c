#include "cub3d.h"

static int	check_number_of_array(char **ceiling_floor_data)
{
	int	i;

	i = 0;
	while(ceiling_floor_data[i])
		i++;
	return(i);
}

static int	check_if_number_superior_to_four(char **ceiling_floor_data)
{
	int i;
	int len;

	i = 1;
	while(ceiling_floor_data[i])
	{
		len = 0;
		while (ceiling_floor_data[i][len])
		{
			len++;
			if (len > 4)
				return (EXIT_FAILURE);
		}
		i++;
	}
}

static int	check_if_ceiling_floor_have_comma(char *ceiling_floor_data, int i, int *commas)
{
	int len;

	len = ft_strlen(ceiling_floor_data);
	if (len == 1) // ici si on a 1 seul caractere, soit c'est une virgule et ok,
					// si c'est autre chose quun chiffre cést fini
					// si le dernier est seul et une virgule cést mort
	{
		if (ft_strncmp(ceiling_floor_data[0], ",", 1) && i != 1)
			(*commas)++;
		else if (!ft_strncmp(ceiling_floor_data[0], ",", 1) && i == 4)
			return(EXIT_FAILURE);
		else if (!ft_isdigit(ceiling_floor_data[0]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_strings(char **ceiling_floor_data)
{
	int	i;
	int	j;
	int len;
	int	commas;

	i = 1;
	commas = 0;
	while (ceiling_floor_data[i])
	{
		j = 0;
		if (check_if_ceiling_floor_have_comma(ceiling_floor_data, i, &commas))
			return (EXIT_FAILURE);
		while (ceiling_floor_data[i][j]) // ici on check si les 3 premiers chiffres sont bien des chiffres 
		{
			len = ft_strlen(ceiling_floor_data);
			if (ft_strncmp(ceiling_floor_data[i][len], ",", 1))
				break; 
			if (!ft_isdigit(ceiling_floor_data[i][j]) )
				return (EXIT_FAILURE);
			j++;
		}
		if (ceiling_floor_data[i][j]) // On check si le 4eme caract est une virgule
		{
			if (!ft_strncmp(&ceiling_floor_data[j][j], ",", 1))
				return (EXIT_FAILURE);
			commas++;
		}
		i++;
	}
	if (commas != 2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_and_add_color_ceiling_floor(t_data *data, int i)
{
	char	**ceiling_floor_data;
	int		len;

	ceiling_floor_data = ft_split_charset(data->map_info->file_cub[i], " \t");
	len = check_number_of_array(ceiling_floor_data);
	if (ft_strlen(ceiling_floor_data[0]) > 1 || len > 6 || len < 2
		|| check_if_number_superior_to_four(ceiling_floor_data)) 
		// je check si la premiere lettre est len > 1 
		// si plus de 6 strings = error 
		// si seulement 1 string = pas possible
		// si plus de + de 4 lettres c'est pas possible 
	{
		free_double_str(ceiling_floor_data);
		return (EXIT_FAILURE);
	}
	if (check_strings(ceiling_floor_data))
	{
		free_double_str(ceiling_floor_data);
		return (EXIT_FAILURE);
	}
	free_double_str(ceiling_floor_data);
	return (EXIT_SUCCESS);
}