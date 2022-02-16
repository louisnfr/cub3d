/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:31:38 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/15 17:29:16 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	arg_error(void)
{
	printf("Error:\nbad argument(s)\n");
	exit (SUCCESS);
}

static	void	check_cub_endof_arg(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (ft_strncmp(&arg[len - 4], ".cub", 4))
		arg_error();
}

static void	check_extension(char *s)
{
	int	fd;

	fd = open(s, __O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		arg_error();
	}
	fd = open(s, O_RDONLY | __O_NOFOLLOW);
	if (fd < 0)
		arg_error();
	close(fd);
	if (!ft_strnstr(s, ".cub", ft_strlen(s)))
		arg_error();
	check_cub_endof_arg(s);
}

void	check_input(int ac, char **av)
{
	if (ac != 3) // bonus
		arg_error();
	check_extension(av[1]);
	check_extension(av[2]); // bonus
}
