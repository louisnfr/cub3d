#include "cub3d.h"

/* Function to store the color of every pixel of the textures.
    - The 3 first line are for the floor
    - the 3 last line are for the ceiling
*/

static void store_color_buffer(t_data *data, t_ray_b *ray_b, int y, int x)
{
    u_int32_t   color;

    color = data->textures->wall_so.tex[TEX_W * ray_b->ty + ray_b->tx];
    color = (color >> 1) & 8355711;
    ray_b->buffer[y][x] = color;
    color = data->textures->doors.tex[(TEX_W * ray_b->ty) + ray_b->tx];
    color = (color >> 1) & 8355711;
    ray_b->buffer[WIN_H - y - 1][x] = color;
}

/* Function to began the raycasting. it is the Width loop of the main function
Here we are doing the raycasting vertically
and not horizontally for efficiency purpose.
- We get the coordinate for every pixel here

*/
static  void    ray_x(t_ray_b *ray_b)
{
    ray_b->cellx = (int)(ray_b->floorx);
    ray_b->celly = (int)(ray_b->floory);
    ray_b->tx = (int)(TEX_W * (ray_b->floorx - ray_b->cellx)) & (TEX_W - 1);
    ray_b->ty = (int)(TEX_H * (ray_b->floory - ray_b->celly)) & (TEX_H - 1);
    ray_b->floorx += ray_b->floorstepx;
    ray_b->floory += ray_b->floorstepy;
}

/* Loop for the height
    p = current pixel distance from the center of the screen
    posZ = height of the center of the screen
    rowdistance = distance to move to the next unit
    floorx - floory = real world coordinates of the leftmost column.
                        This will be updated as we step to the right.
*/

static void ray_y(t_ray_b *ray_b, t_player *player, int y)
{
    ray_b->dirx0 = player->vector.dx - player->camera.px;
    ray_b->diry0 = player->vector.dy - player->camera.py;
    ray_b->dirx1 = player->vector.dx + player->camera.px;
    ray_b->diry1 = player->vector.dy + player->camera.py;
    ray_b->p = y - (WIN_H * 0.5);
    ray_b->posz = 0.5 * WIN_H;
    ray_b->rowdistance = ray_b->posz / ray_b->p;
    ray_b->floorstepx =
        ray_b->rowdistance * (ray_b->dirx1 - ray_b->dirx0) / WIN_W;
    ray_b->floorstepy =
        ray_b->rowdistance * (ray_b->diry1 - ray_b->diry0) / WIN_W;
    ray_b->floorx = player->vector.x +  ray_b->rowdistance * ray_b->dirx0;
    ray_b->floory = player->vector.y +  ray_b->rowdistance * ray_b->diry0;
}

int	floor_casting_bonus(t_data *data, t_player *player)
{
	int     y;
	t_ray   ray;
	t_ray_b ray_b;
    int     x;

	y = 0;
	ray = data->ray;
	ray_b = data->ray_b;
	while (y < WIN_H)
	{
        ray_y(&ray_b, player, y);
        x = 0;
        while (x < WIN_W)
        {
            ray_x(&ray_b);
            store_color_buffer(data, &ray_b, y, x);
            x++;
        }
        y++;
    }
    draw_floor_ceiling_bonus(&ray_b, data);
    return  (SUCCESS);
}
