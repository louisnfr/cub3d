#include "cub3d.h"

/*
We are doing the initial set up of the ray
- camx -> When is the camera we are (-1 = left, 0 = center, 1 = right)
- ray->dir x - y = direction of the ray
- ray->map x - y = current square of the ray
- delta x - y = distance to go to the next x or y.

*/
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

/*
- We are doing the initial set up for the dda
- dda algorithm will jump of one square in each loop eiter in a x or y direction
- ray->dist x or y = distance from the ray start position to the
	next x or y position
- if x or y < 0 go the next x or y to the left
- if x or y > 0 fo the next x or y to the right
*/

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

/*
- Here we are doing the loop which increment 1 square until we hit a wall
- If the distx < disty, x is the closest point from the ray
- We increment dist(x or y) to be the next value (x or y) in the map
*/
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
		if (map[ray->mapy][ray->mapx] == '1'
			|| map[ray->mapy][ray->mapx] == '2') // BONUS
			hit = 1;
	}
	if (ray->side == 0)
		ray->pw = (ray->mapx - player->x + (1 - ray->stepx) * 0.5) / ray->dirx;
	else
		ray->pw = (ray->mapy - player->y + (1 - ray->stepy) * 0.5) / ray->diry;
}

/*
We set the ray to be drawn on the map
- line_height = height of the line to be drawn on screen
- start and end are the coordinate to draw the wall
*/

static void	put_ray_to_image(t_ray *ray, t_tex *t, int x, t_data *data)
{

	t->line_height = (int)(WIN_H / ray->pw);
	t->start = -t->line_height * 0.5 + WIN_H * 0.5;
	if (t->start < 0)
		t->start = 0;
	t->end = t->line_height * 0.5 + WIN_H * 0.5;
	if (t->end >= WIN_H)
		t->end = WIN_H - 1;
	t_point	ceiling = {0, t->start, 0};
	t_point	floor = {t->end, WIN_H - 1, 0};
	put_vline(x, ceiling, data->textures->ceiling_color.hex_color, data->mlx);
	put_vline(x, floor, data->textures->floor_color.hex_color, data->mlx);
}

// Actual raycasting on the Field of view of the player

int	raycasting(t_player *player, t_data *data)
{
	t_tex	tex;
	t_ray	ray;
	int		x;

	x = -1;
	ray = data->ray;
	while (++x < WIN_W)
	{
		create_ray(x, &ray, player);
		set_dda(&ray, &player->vector);
		perform_dda(&ray, &player->vector, data->map_info->map);
		put_ray_to_image(&ray, &tex, x, data);
		draw_texture(&ray, &tex, x, data);
	}
	return (SUCCESS);
}
