#include "cub3d.h"

// Check if we have only one beginning face for the

static	int	check_error_initial_position_player(char **map, char initial_position)
{
	int count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == initial_position)
			{
				// AJOUTER LE STOCKAGE DE LINFO ICI initial du player ici 
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
static	int	letters_are_more_than_once(char **map)
{
	int	count;

	count = 0;
	count = count + check_error_initial_position_player(map, 'W');
	count = count + check_error_initial_position_player(map, 'E');
	count = count + check_error_initial_position_player(map, 'N');
	count = count + check_error_initial_position_player(map, 'S');
	if (count != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int	check_letters_map(char letter)
{
	if (letter == '1')
		return (EXIT_SUCCESS);
	else if (letter == '0')
		return (EXIT_SUCCESS);
	else if (letter == ' ')
		return (EXIT_SUCCESS);
	else if (letter == '\t')
		return (EXIT_SUCCESS);
	else if (letter == 'N')
		return (EXIT_SUCCESS);
	else if (letter == 'S')
		return (EXIT_SUCCESS);
	else if (letter == 'W')
		return (EXIT_SUCCESS);
	else if (letter == 'E')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static	int	check_all_the_letters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_letters_map(map[i][j]))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

// Check if other letters than authorized
// Check if Starting position player is > 0

int	check_if_letters_are_good(t_data *data)
{
	if (check_all_the_letters(data->map_info->map))
		return (EXIT_FAILURE);
	if (letters_are_more_than_once(data->map_info->map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}