#include "cub3d.h"

int	ft_isdigit_comma(int c, int *commas)
{
	if ((c >= 48 && c <= 57) || c == ',')
	{
		if (c == ',')
			(*commas)++;
		return (1);
	}
	return (0);
}
