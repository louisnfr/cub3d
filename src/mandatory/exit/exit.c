/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:17:50 by lraffin           #+#    #+#             */
/*   Updated: 2022/02/24 16:17:50 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit_parsing(t_data *data, char *error_message)
{
	ft_error_message(error_message);
	free_data(data);
	exit(1);
}

int	exit_all(t_data *data)
{
	free_data(data);
	exit(FAILURE);
	return (1);
}
