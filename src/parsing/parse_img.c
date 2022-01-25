#include "cub3d.h"

static	int add_face_wall_we_to_mlx(t_data *data, char *path_img)
{
	int	img_width;
	int	img_height;

	data->sprites->wall_we = mlx_xpm_file_to_image(data->mlx->ptr,
	path_img, &img_width, &img_height);
	if (data->sprites->wall_we != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


static	int add_face_wall_ea_to_mlx(t_data *data, char *path_img)
{
	int	img_width;
	int	img_height;

	data->sprites->wall_ea = mlx_xpm_file_to_image(data->mlx->ptr,
	path_img, &img_width, &img_height);
	if (data->sprites->wall_ea != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int add_face_wall_so_to_mlx(t_data *data, char *path_img)
{
	int	img_width;
	int	img_height;

	data->sprites->wall_so = mlx_xpm_file_to_image(data->mlx->ptr,
	path_img, &img_width, &img_height);
	if (data->sprites->wall_so != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int add_face_wall_no_to_mlx(t_data *data, char *path_img)
{
	int	img_width;
	int	img_height;

	data->sprites->wall_no = mlx_xpm_file_to_image(data->mlx->ptr, path_img, &img_width, &img_height);
	if (!data->sprites->wall_no)
	{
		printf("PROUT_deeeebug\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	add_img_wall_to_mlx(t_data *data, char *face_wall, char *path_img)
{
	ft_memset(data->sprites, 0, sizeof (t_sprites));
	if (!ft_strcmp(face_wall, "NO"))
	{
		if (add_face_wall_no_to_mlx(data, path_img))
		{
			printf("PROUT_debug1\n");
			return (EXIT_FAILURE);
		}
	}
	else if(!ft_strcmp(face_wall, "SO"))
	{
		if (add_face_wall_so_to_mlx(data, path_img))
		{
			printf("PROUT_debug2\n");
			return (EXIT_FAILURE);
		}
	}
	else if(!ft_strcmp(face_wall, "EA"))
	{
		printf("PROUT_debug3\n");
		if (add_face_wall_ea_to_mlx(data, path_img))
			return (EXIT_FAILURE);
	}
	else if(!ft_strcmp(face_wall, "WE"))
	{
		printf("PROUT_debug4\n");
		if (add_face_wall_we_to_mlx(data, path_img))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}