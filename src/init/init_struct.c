#include "cub3d.h"

void	init_struct(t_data *data)
{
	data->mlx = NULL;
	ft_memset(data->map_info, 0, sizeof(t_map));
	ft_memset(data->sprites, 0, sizeof(t_sprites));
	// ft_memset(data->ray, 0, sizeof (t_ray));
	// ft_memset(data->mouse, 0, sizeof (t_mouse));
	// ft_memset(data->sprites->wall_ea, 0, sizeof (t_img));
	// ft_memset(data->sprites->wall_no, 0, sizeof (t_img));
	// ft_memset(data->sprites->wall_so, 0, sizeof (t_img));
	// ft_memset(data->sprites->wall_we, 0, sizeof (t_img));
}
