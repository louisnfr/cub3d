/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:31:38 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/21 17:39:45 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	arg_error(void)
{
	printf("error: bad arguments\n");
	exit (EXIT_FAILURE);
}

static void	check_extension(char *s)
{
	if (open(s, O_RDONLY) < 0)
		arg_error();
	if (!ft_strnstr(s, ".ber", ft_strlen(s)))
		arg_error();
}

void	check_input(int ac, char **av)
{
	if (ac != 2)
		arg_error();
	check_extension(av[1]);
}
