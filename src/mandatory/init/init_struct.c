#include "cub3d.h"

void	init_struct(t_data *data)
{
	data->mlx = NULL;
	ft_memset(data->map_info, 0, sizeof(t_map));
	ft_memset(data->sprites, 0, sizeof(t_sprites));
	ft_memset(data->textures, 0, sizeof(t_textures));
}

t_move *init_move(t_data *data)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (!move)
		ft_exit_parsing(data,"Error\nProblem with your memory_allocation\n");
	ft_memset(move, 0, sizeof(t_move));
	return (move);
}

t_mlx	*init_mlx(t_data *data)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		ft_exit_parsing(data,"Error\nProblem with your memory_allocation\n");
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIN_W, WIN_H, "cub3d");
	mlx->img = mlx_new_image(mlx->ptr, WIN_W, WIN_H);
	mlx->buf1 = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->length, &mlx->endian);
	return (mlx);
}

t_player	*init_player(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		ft_exit_parsing(data,"Error\nProblem with your memory_allocation\n");
	player->vector.x = data->map_info->x_init + 0.5;
	player->vector.y = data->map_info->y_init + 0.5;
	player->vector.z = 0;
	set_player_dir(player, data);
	return (player);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->sprites = malloc(sizeof(t_sprites));
	data->textures = malloc(sizeof(t_textures));
	data->map_info = malloc(sizeof(t_map));
	if (!data || !data->sprites || !data->map_info)
		ft_exit_parsing(data,"Error\nProblem with your memory_allocation\n");
	data->move = init_move(data);
	return (data);
}
