#include "cub3d.h"

/* ici on stock dans notre int* la texture de chaque mur
	- On malloc.
	- On remplit de 0 nos int* de textures.
*/
static void	cub_init_textures(t_textures *wall, t_data *data)
{
	int		j;

	wall->wall_no.tex = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
	wall->wall_so.tex = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
	wall->wall_ea.tex = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
	wall->wall_we.tex = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
	wall->doors.tex = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
	wall->ceiling.tex = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
	wall->floor.tex = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
	if (!wall->wall_no.tex || !wall->wall_so.tex || !wall->wall_ea.tex
		|| !wall->wall_we.tex || !wall->doors.tex)
		ft_exit_parsing(data, "Error\nMalloc failed\n");
	j = 0;
	while (j < TEX_W * TEX_H)
	{
		wall->wall_no.tex[j] = 0;
		wall->wall_so.tex[j] = 0;
		wall->wall_ea.tex[j] = 0;
		wall->wall_we.tex[j] = 0;
		wall->doors.tex[j] = 0;
		wall->floor.tex[j] = 0;
		wall->ceiling.tex[j] = 0;
		j++;
	}
}

/* On transforme le xpm en image et on leur attribut une adresse dans un int
	- On stock tout dans notre texture qu'on a malloc juste avant
*/

static void	cub_load_xpm(t_mlx *mlx, int *tex, char *path)
{
	int	x;
	int	y;
	mlx->img = mlx_xpm_file_to_image(mlx->ptr, path, &mlx->x, &mlx->y);
	if (mlx->img)
		mlx->add = (int *)mlx_get_data_addr(mlx->img,
							&mlx->bpp, &mlx->length, &mlx->endian);
	y = 0;
	while (y < mlx->y)
	{
		x = 0;
		while (x < mlx->x)
		{
			tex[mlx->x * y + x] = mlx->add[mlx->x * y + x];

			x++;
		}
		y++;
	}
	// TROUVER MOYEN DE FREE
	// mlx_destroy_image(mlx->ptr, mlx->img);
}

// On init notre texture et on lui stock une valeur

void	cub_load_textures(t_mlx *mlx, t_textures *wall, t_data *data)
{
	cub_init_textures(wall, data);
	cub_load_xpm(mlx, wall->wall_no.tex, wall->wall_no.path_img);
	cub_load_xpm(mlx, wall->wall_so.tex, wall->wall_so.path_img);
	cub_load_xpm(mlx, wall->wall_ea.tex, wall->wall_ea.path_img);
	cub_load_xpm(mlx, wall->wall_we.tex, wall->wall_we.path_img);
	cub_load_xpm(mlx, wall->doors.tex, "./images/eagle.xpm");
	cub_load_xpm(mlx, wall->ceiling.tex, "./images/eagle.xpm");
	cub_load_xpm(mlx, wall->floor.tex, "./images/eagle.xpm");
}
