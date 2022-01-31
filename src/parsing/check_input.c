/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:55:50 by vbachele          #+#    #+#             */
/*   Updated: 2022/01/31 14:55:51 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	arg_error(void)
{
	printf("Error:\nbad argument(s)\n");
	exit (EXIT_FAILURE);
}

static void	check_extension(char *s)
{
	int	fd;

	fd = open(s, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		arg_error();
	}
	if (open(s, O_RDONLY | O_NOFOLLOW) < 0)
		arg_error();
	if (!ft_strnstr(s, ".cub", ft_strlen(s)))
		arg_error();
}

void	check_input(int ac, char **av)
{
	if (ac != 2)
		arg_error();
	check_extension(av[1]);
}
