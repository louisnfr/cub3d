/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:55:37 by vbachele          #+#    #+#             */
/*   Updated: 2022/02/06 18:26:39 by vbachele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// a changer avec le nouveau parsing car pas pertinent
//de recuperer l'info tout de suite
static char	**allocate_file(t_map *map_info, t_data *data)
{
	char	**map;
	int		i;

	map = ft_calloc(map_info->cubfile_number_lines + 1, sizeof(char *));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < map_info->cubfile_number_lines)
	{
		map[i] = ft_calloc(map_info->cubfile_width_line + 1, sizeof(char));
		if (!map[i])
			ft_exit_parsing(data,"Error\n"
			"Problem with your memory_allocation\n");
	}
	map[i] = 0;
	return (map);
}

// On remplit la map avec toutes les infos
static int	fill_file(t_data *data, char *av)
{
	char	*line;
	int		ret;
	int		fd;
	int		i;
	int		j;

	fd = open(av, O_RDONLY);
	data->map_info->file_cub = allocate_file(data->map_info, data);
	if (!data->map_info->file_cub || fd < 0)
		ft_exit_parsing(data,"Error\nProblem with your memory_allocation\n");
	ret = 1;
	j = 0;
	while (ret)
	{
		i = -1;
		ret = get_next_line(fd, &line);
		if (ret < 0)
			ft_exit_parsing(data,"Error\nProblem when reading your fd\n");
		while (++i < ft_strlen(line))
			data->map_info->file_cub[j][i] = line[i];
		j++;
		free(line);
	}
	close(fd);
	return (SUCCESS);
}

// On recupere la width et la height du fichier ici
//(a changer avec le parsing de cub3d) a changer egalement

int	get_file(t_data *data, char *av)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_exit_parsing(data,"Error\nProblem on opening your fd\n");
	ret = 1;
	ft_memset(data->map_info, 0, sizeof(t_map));
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
		{
			close(fd);
			ft_exit_parsing(data,"Error\nProblem when reading your fd\n");
		}
		if (ft_strlen(line) > data->map_info->cubfile_width_line)
			data->map_info->cubfile_width_line = ft_strlen(line);
		data->map_info->cubfile_number_lines++;
		free(line);
	}
	close(fd);
	return (fill_file(data, av));
}
