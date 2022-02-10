#include "cub3d.h"

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
        // rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
        ray_b.dirx0 = player->vector.dx - player->camera.px;
        ray_b.diry0 = player->vector.dy - player->camera.py;
        ray_b.dirx1 = player->vector.dx + player->camera.px;
        ray_b.diry1 = player->vector.dy + player->camera.py;

        // Current y position compared to the center of the screen (the horizon)
        ray_b.p = y - (WIN_H * 0.5);

        // Vertical position of the camera.
        ray_b.posz = 0.5 * WIN_H;

        // Horizontal distance from the camera to the floor for the current row.
        // 0.5 is the z position exactly in the middle between floor and ceiling.
        ray_b.rowdistance = ray_b.posz / ray_b.p;

        // calculate the real world step vector we have to add for each x (parallel to camera plane)
        // adding step by step avoids multiplications with a weight in the inner loop
        ray_b.floorstepx = ray_b.rowdistance * (ray_b.dirx1 - ray_b.dirx0) / WIN_W;
        ray_b.floorstepy = ray_b.rowdistance * (ray_b.diry1 - ray_b.diry0) / WIN_W;
        // real world coordinates of the leftmost column. This will be updated as we step to the right.
        ray_b.floorx = player->vector.x +  ray_b.rowdistance * ray_b.dirx0;
        ray_b.floory = player->vector.y +  ray_b.rowdistance * ray_b.diry0;
        x = 0;
        while (x < WIN_W)
        {
            // the cell coord is simply got from the integer parts of floorX and floorY
            ray_b.cellx = (int)(ray_b.floorx);
            ray_b.celly = (int)(ray_b.floory);

            // get the texture coordinate from the fractional part
            ray_b.tx = (int)(TEX_W * (ray_b.floorx - ray_b.cellx)) & (TEX_W - 1);
            ray_b.ty = (int)(TEX_H * (ray_b.floory - ray_b.celly)) & (TEX_H - 1);

            ray_b.floorx += ray_b.floorstepx;
            ray_b.floory += ray_b.floorstepy;

            // choose texture and draw the pixel
            // int floorTexture = 3;
            // int ceilingTexture = 6;
            u_int32_t     color;

            // floor
            color = data->textures->wall_so.tex[TEX_W * ray_b.ty + ray_b.tx];
            color = (color >> 1) & 8355711; // make a bit darker
            ray_b.buffer[y][x] = color;
            //put_pixel(x, y, WHITE, data->mlx);
            //ceiling (symmetrical, at screenHeight - y - 1 instead of y)
            color = data->textures->doors.tex[(TEX_W * ray_b.ty) + ray_b.tx];
            color = (color >> 1) & 8355711; // make a bit darker
            //printf("PROUT_debug %d\n", color);
            ray_b.buffer[WIN_H - y - 1][x] = color;
            //put_pixel(x, WIN_H - y - 1, buffer[WIN_H - y - 1][x], data->mlx);
            x++;
        }
        y++;
    }

	int k = 0;
	while (k < (WIN_H - k))
	{
		x = 0;
		while (x < WIN_W)
		{
            put_pixel(x, k, ray_b.buffer[k][x], data->mlx);
			x++;
		}
		k++;
	}
    while (k < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
            put_pixel(x, k, ray_b.buffer[k][x], data->mlx);
			x++;
		}
		k++;
	}

    return (SUCCESS);
}