/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:23:03 by vbachele          #+#    #+#             */
/*   Updated: 2021/09/02 22:30:20 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube_3d.h"

int	get_next_line(int fd, char **line)
{
	int		ret;
	int		i;
	char	buf;

	if (!line)
		return (-1);
	*line = malloc(1234567);
	**line = 0;
	i = 0;
	buf = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, &buf, 1);
		if (buf == '\n')
			break ;
		(*line)[i] = buf;
		buf = 0;
		i++;
	}
	(*line)[i] = 0;
	if (ret == -1)
		**line = 0;
	return (ret);
}