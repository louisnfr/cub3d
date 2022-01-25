/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:26:00 by lraffin           #+#    #+#             */
/*   Updated: 2022/01/24 22:52:09 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		precalculate_rays(t_data *data)
{
	(void)data;
	// position of the player
	double	posX = 2;
	double	posY = 2;
	// direction of the player
	double	dirX = -1;
	double	dirY = 0;
	// camera plane of the player
	double	planeX = 0;
	double	planeY = 0.66;
	// fps
	double	time = 0;
	double	oldtime = 0;

	int	x = -1;
	if (data->mlx->img)
		mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	data->mlx->img = mlx_new_image(data->mlx->ptr, WIN_W, WIN_H);
	data->mlx->buf1 = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
		&data->mlx->length, &data->mlx->endian);
	while(++x < WIN_W * 2)
	{
		double cameraX = 2 * x / WIN_W - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = posX;
		int mapY = posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			for(int q=0; data->map_info->map[q]; q++)
				printf("data->map_info->map[%d]: %s\n", q, data->map_info->map[q]);
			printf("map[%d][%d]\n", mapX, mapY);
			// printf("map[%d][%d] = %c\n", mapX, mapY, data->map_info->map[mapX][mapY]);
			//Check if ray has hit a wall
			if(mapX >= 0 && mapX < 9 && mapY >= 0 && mapY < 9 && data->map_info->map[mapX][mapY] > 0)
				hit = 1;
		}
		if(side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) * 0.5) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) * 0.5) / rayDirY;

		int lineHeight = (int)(WIN_H / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_H / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_H / 2;
		if(drawEnd >= WIN_H)
			drawEnd = WIN_H - 1;

		//choose wall color
		// int color;
		// switch(data->map_info->map[mapX][mapY])
		// {
		// 	case 1:  color = RED;    break; //red
		// 	case 2:  color = GREEN;  break; //green
		// 	case 3:  color = BLUE;   break; //blue
		// 	case 4:  color = WHITE;  break; //white
		// 	default: color = YELLOW; break; //yellow
		// }

		//give x and y sides different brightness
		// if(side == 1)
		// 	color = color * 0.5;

		//draw the pixels of the stripe as a vertical line
		t_point a = {x, drawStart};
		t_point b = {x, drawEnd};
		put_line(a, b, RED, data->mlx);
	}
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->mlx->img, 0, 0);
	return (0);
}
