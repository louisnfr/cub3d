#include "cub3d.h"

/*** Here we allocate the file sprite to add easily sprites/img
***/

static char	**allocate_file(t_data *data, int len, int number_l)
{
	char	**map;
	int		i;

	map = ft_calloc(number_l, sizeof(char *));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < number_l)
	{
		map[i] = ft_calloc(len + 1, sizeof(char));
		if (!map[i])
			ft_exit_parsing(data,"Error\n"
			"Problem with your memory_allocation\n");
	}
	map[i] = 0;
	return (map);
}


static int	get_file_sprites(t_data * data, char *av, int len, int number_l)
{
	char	*line;
	int		ret;
	int		fd;
	int		i;
	int		j;

	fd = open(av, O_RDONLY);
	ft_memset(&data->sprite_f, 0, sizeof(t_sprite_f));
	data->sprite_f.arg_sprite =
		allocate_file(data, len, number_l);
	if (!data->sprite_f.arg_sprite || fd < 0)
		ft_exit_parsing(data,"Error\nProblem with your memory_allocation\n");
	ret = 1;
	j = 0;
	while (ret)
	{
		i = -1;
		ret = get_next_line(fd, &line);
		if (ret < 0)
			ft_exit_parsing(data,"Error\nProblem when reading your fd\n");
		data->sprite_f.arg_sprite[j] =
			ft_calloc((ft_strlen(line) + 1), sizeof(char));
		while (++i < ft_strlen(line))
			data->sprite_f.arg_sprite[j][i] = line[i];
		j++;
		free(line);
	}
	close(fd);
	return (SUCCESS);
}

/***
Here we fill the file sprite to add easily sprites/img
***/

int	parse_file_sprites(t_data *data, char *av)
{
	char	*line;
	int		fd;
	int		ret;
	int 	len;
	int		number_l;

	len = 0;
	number_l = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_exit_parsing(data,"Error\nProblem on opening your fd\n");
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
		{
			close(fd);
			ft_exit_parsing(data,"Error\nProblem when reading your fd\n");
		}
		if (ft_strlen(line) > len)
			len = ft_strlen(line);
		number_l++;
		free(line);
	}
	close(fd);
	return (get_file_sprites(data, av, len, number_l));
}
