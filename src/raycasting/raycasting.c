#include "cub3d.h"

static void	create_ray(int x, t_ray *ray, t_player *player)
{
	double	camx;

	camx = 2 * x / (double)WIN_W - 1;
	ray->dirx = player->vector.dx + player->camera.px * camx;
	ray->diry = player->vector.dy + player->camera.py * camx;
	ray->mapx = (int)player->vector.x;
	ray->mapy = (int)player->vector.y;
	ray->deltax = fabs(1 / ray->dirx);
	ray->deltay = fabs(1 / ray->diry);
}

static void	set_dda(t_ray *ray, t_vector *player)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->distx = (player->x - ray->mapx) * ray->deltax;
	}
	else
	{
		ray->stepx = 1;
		ray->distx = (ray->mapx + 1.0 - player->x) * ray->deltax;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->disty = (player->y - ray->mapy) * ray->deltay;
	}
	else
	{
		ray->stepy = 1;
		ray->disty = (ray->mapy + 1.0 - player->y) * ray->deltay;
	}
}

static void	perform_dda(t_ray *ray, t_vector *player, char **map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->distx < ray->disty)
		{
			ray->distx += ray->deltax;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->disty += ray->deltay;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (map[ray->mapy][ray->mapx] == '1')
			hit = 1;
	}
	if (ray->side == 0)
		ray->pw = (ray->mapx - player->x + (1 - ray->stepx) * 0.5) / ray->dirx;
	else
		ray->pw = (ray->mapy - player->y + (1 - ray->stepy) * 0.5) / ray->diry;
}

static void	put_ray_to_image(t_ray *ray, t_tex *t, int x, t_data *data)
{

	t->line_height = (int)(WIN_H / ray->pw);
	t->start = -t->line_height * 0.5 + WIN_H * 0.5;
	if (t->start < 0)
		t->start = 0;
	t->end = t->line_height * 0.5 + WIN_H * 0.5;
	if (t->end >= WIN_H)
		t->end = WIN_H - 1;
	// int		color;
	// color = BLUE;
	// if (ray->side == 1)
	// 	color = color * 0.5;
	// t_point	wall = {t->start, t->end, 0};
	t_point	ceiling = {0, t->start, 0};
	t_point	floor = {t->end, WIN_H - 1, 0};
	put_vline(x, ceiling, data->sprites->ceiling_color.hex_color, data->mlx);
	put_vline(x, floor, data->sprites->floor_color.hex_color, data->mlx);
	// put_vline(x, wall, color, data->mlx);
}

int	raycasting(t_player *player, t_data *data)
{
	int		**texture;

	texture = malloc(sizeof(int *) * 2);
	for (int k = 0; k < 1; k++)
		texture[k] = malloc(sizeof(int) * (1000 * TEX_H * TEX_W));
	for(int y = 0; y < TEX_W; y++)
	{
		for(int x = 0; x < TEX_H; x++)
			texture[0][TEX_W * y + x] = GREEN;  //flat grey texture
	}

	t_tex	tex;
	t_ray	ray;
	int		x;

	x = -1;
	while (++x < WIN_W)
	{
		create_ray(x, &ray, player);
		set_dda(&ray, &player->vector);
		perform_dda(&ray, &player->vector, data->map_info->map);
		put_ray_to_image(&ray, &tex, x, data);
		set_texture(&ray, &tex, x, data, texture);
	}
	return (SUCCESS);
}
